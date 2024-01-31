import copy
import os
import sys
import numpy as np
import re
import code
import tempfile
import networkx as nx
import random

location="./data"



def parse(path, dump=False):
    top = path.split('/')[-1].replace('.bench','')
    with open(path, 'r') as f:
        data = f.read()
    return verilog2gates(data, dump)



def verilog2gates(verilog, dump):
    Dict_gates={
    'xor': [0,1,0,0,0,0,0,0,0],
    'XOR': [0,1,0,0,0,0,0,0,0],
    'OR':  [0,0,1,0,0,0,0,0,0],
    'or':  [0,0,1,0,0,0,0,0,0],
    'XNOR':[0,0,0,1,0,0,0,0,0],
    'xnor':[0,0,0,1,0,0,0,0,0],
    'and': [0,0,0,0,1,0,0,0,0],
    'AND': [0,0,0,0,1,0,0,0,0],
    'nand':[0,0,0,0,0,1,0,0,0],
    'NAND':[0,0,0,0,0,1,0,0,0],
    'buf': [0,0,0,0,0,0,0,1,0],
    'BUF': [0,0,0,0,0,0,0,1,0],
    'not': [0,0,0,0,0,0,1,0,0],
    'NOT': [0,0,0,0,0,0,1,0,0],
    'mux': [0,0,0,0,0,0,0,0,1],
    'MUX': [0,0,0,0,0,0,0,0,1],
    'nor': [1,0,0,0,0,0,0,0,0],
    'NOR': [1,0,0,0,0,0,0,0,0],
}
    G = nx.DiGraph()
    ML_count=0
    regex= "\s*(\S+)\s*=\s*(BUF|NOT|buf|not)\((\S+)\)\s*"
    for output, function, net_str in re.findall(regex,verilog,flags=re.I |re.DOTALL):
        input=net_str.replace(" ","")

        G.add_edge(input,output)
        G.nodes[output]['gate'] = function
        G.nodes[output]['count'] = ML_count
        if dump:
            feat=Dict_gates[function]
            for item in feat:
                f_feat.write(str(item)+" ")
            f_feat.write("\n")
            f_cell.write(str(ML_count)+" assign for output "+output+"\n")
            f_count.write(str(ML_count)+"\n")
        ML_count+=1
    regex= "(\S+)\s*=\s*(OR|XOR|AND|NAND|XNOR|NOR|MUX|or|xor|and|nand|xnor|nor|mux)\((.+?)\)\s*"
    for output, function, net_str in re.findall(regex,verilog,flags=re.I | re.DOTALL):
        nets = net_str.replace(" ","").replace("\n","").replace("\t","").split(",")
        inputs = nets
        G.add_edges_from((net,output) for net in inputs)
        G.nodes[output]['gate'] = function
        G.nodes[output]['count'] = ML_count
        if dump:
            feat=Dict_gates[function]
            for item in feat:
                f_feat.write(str(item)+" ")
            f_feat.write("\n")
            f_cell.write(str(ML_count)+" assign for output "+output+"\n")
            f_count.write(str(ML_count)+"\n")
        ML_count+=1
    for n in G.nodes():
        if 'gate' not in G.nodes[n]:
            G.nodes[n]['gate'] = 'input'
    for n in G.nodes:
        G.nodes[n]['output'] = False
    out_regex = "OUTPUT\((.+?)\)\n"
    for net_str in re.findall(out_regex,verilog,flags= re.I | re.DOTALL):
        nets = net_str.replace(" ","").replace("\n","").replace("\t","").split(",")
        for net in nets:
            if net not in G:
                print("Output "+net+" is Float")
            else:
                G.nodes[net]['output'] = True
    if dump:
        for u,v in G.edges:
            if 'count' in G.nodes[u].keys() and 'count' in G.nodes[v].keys():
                f_link_train.write(str(G.nodes[u]['count'])+" "+str(G.nodes[v]['count'])+"\n")
    return G


if __name__=='__main__':
    if not os.path.exists(location):
        os.mkdir(location)
        print("Directory '% s' created" % location)
    f_feat = open(location+"/feat.txt", "w")
    f_cell = open(location+"/cell.txt", "w")
    f_count = open(location+"/count.txt", "w")
    f_link_test = open(location+"/links_test.txt", "w")
    f_link_train = open(location+"/links_train_temp.txt", "w")
    f_link_train_f = open(location+"/links_train.txt", "w")
    f_link_test_neg = open(location+"/link_test_n.txt", "w")
    c = parse("/home/lan/bench2G/c1355_locked.bench", True)
    #new_c = parse('/home/lan/bench2G/c1355_locked.bench')