module s27(
    G0,
    G1,
    G2,
    G3,
    G17
);
    input G0;
    input G1;
    input G2;
    input G3;
    output G17;

    // Internal wires
    wire G5;
    wire G6;
    wire G7;
    wire G14;
    wire G8;
    wire G15;
    wire G16;
    wire G9;
    wire G10;
    wire G11;
    wire G12;
    wire G13;
    
    DFFSRX1 g_G5 (.Q(G5), .QN(), .D(G10), .CK(clk), .SN(1'b1), .RN(rstn));
    DFFSRX1 g_G6 (.Q(G6), .QN(), .D(G11), .CK(clk), .SN(setn), .RN(1'b1));
    DFFSRX1 g_G7 (.Q(G7), .QN(), .D(G13), .CK(clk), .SN(setn), .RN(1'b1));
    INVX1 g_G14 (.A(G0), .Y(G14));
    INVX1 g_G17 (.A(G11), .Y(G17));
    AND2X1 g_G8 (.A(G14), .B(G6), .Y(G8));
    OR2X1 g_G15 (.A(G12), .B(G8), .Y(G15));
    OR2X1 g_G16 (.A(G3), .B(G8), .Y(G16));
    NAND2X1 g_G9 (.A(G16), .B(G15), .Y(G9));
    NOR2X1 g_G10 (.A(G14), .B(G11), .Y(G10));
    NOR2X1 g_G11 (.A(G5), .B(G9), .Y(G11));
    NOR2X1 g_G12 (.A(G1), .B(G7), .Y(G12));
    NOR2X1 g_G13 (.A(G2), .B(G12), .Y(G13));
    
endmodule