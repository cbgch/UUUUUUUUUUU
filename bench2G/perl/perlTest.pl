$name="aAbBcC";
if($name =~ m/ab/i){
    print "pre match: $` \n";     # 输出a
    print "match: $& \n";         # 输出Ab
    print "post match: $' \n";    # 输出BcC
    print "$name\n";

    print "***********************************************************************\n";

    $inn="40 : name";
    if ( $inn =~ m/\s*\[(\d+)\:(\d+)\]\s+(\S+)/ ) {       #\S匹配任何非空白字符
            my $start = $1;
            my $end   = $2;
            my $name  = $3;

            print "start=$start \n";
            print "end=$end\n";
            print "name=$name\n";
    }

    #defined函数测试
    %ports = ('google', 'google.com', 'runoob', 'runoob.com', 'taobao', 'taobao.com');
    my $hash_ref = \%ports;
    print "$hash_ref\n";
    if ( defined( $$hash_ref{"casb"} ) ) {
        #push @current_gate_inputs, $$hash_ref{"A"};
        print "yes\n";
    }else{
        print "no\n";
    }
}
