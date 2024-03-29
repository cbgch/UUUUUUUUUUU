/////////////////////////////////////////////////////////////
// Created by: Synopsys DC Expert(TM) in wire load mode
// Version   : L-2016.03-SP1
// Date      : Wed Jan 10 17:50:42 2024
/////////////////////////////////////////////////////////////


module c1908 ( G101, G104, G107, G110, G113, G116, G119, G122, G125, G128, 
        G131, G134, G137, G140, G143, G146, G210, G214, G217, G221, G224, G227, 
        G234, G237, G469, G472, G475, G478, G898, G900, G902, G952, G953, G3, 
        G6, G9, G12, G30, G45, G48, G15, G18, G21, G24, G27, G33, G36, G39, 
        G42, G75, G51, G54, G60, G63, G66, G69, G72, G57 );
  input G101, G104, G107, G110, G113, G116, G119, G122, G125, G128, G131, G134,
         G137, G140, G143, G146, G210, G214, G217, G221, G224, G227, G234,
         G237, G469, G472, G475, G478, G898, G900, G902, G952, G953;
  output G3, G6, G9, G12, G30, G45, G48, G15, G18, G21, G24, G27, G33, G36,
         G39, G42, G75, G51, G54, G60, G63, G66, G69, G72, G57;
  wire   n211, n212, n213, n214, n215, n216, n217, n218, n219, n220, n221,
         n222, n223, n224, n225, n226, n227, n228, n229, n230, n231, n232,
         n233, n234, n235, n236, n237, n238, n239, n240, n241, n242, n243,
         n244, n245, n246, n247, n248, n249, n250, n251, n252, n253, n254,
         n255, n256, n257, n258, n259, n260, n261, n262, n263, n264, n265,
         n266, n267, n268, n269, n270, n271, n272, n273, n274, n275, n276,
         n277, n278, n279, n280, n281, n282, n283, n284, n285, n286, n287,
         n288, n289, n290, n291, n292, n293, n294, n295, n296, n297, n298,
         n299, n300, n301, n302, n303, n304, n305, n306, n307, n308, n309,
         n310, n311, n312, n313, n314, n315, n316, n317, n318, n319, n320,
         n321, n322, n323, n324, n325, n326, n327, n328, n329, n330, n331,
         n332, n333, n334, n335, n336, n337, n338, n339, n340, n341, n342,
         n343, n344, n345, n346, n347, n348, n349, n350, n351, n352, n353,
         n354, n355, n356, n357, n358, n359, n360, n361, n362, n363, n364,
         n365, n366, n367, n368, n369, n370, n371, n372, n373, n374, n375,
         n376, n377, n378, n379, n380, n381, n382, n383, n384, n385, n386,
         n387, n388;

  XNOR2_X1 U236 ( .A(G107), .B(n211), .ZN(G9) );
  NAND3_X1 U237 ( .A1(n212), .A2(n213), .A3(n214), .ZN(G75) );
  NOR3_X1 U238 ( .A1(n215), .A2(G953), .A3(n216), .ZN(n214) );
  NOR4_X1 U239 ( .A1(n217), .A2(n218), .A3(n219), .A4(n220), .ZN(n216) );
  NOR2_X1 U240 ( .A1(n221), .A2(n222), .ZN(n217) );
  NOR2_X1 U241 ( .A1(n223), .A2(n224), .ZN(n222) );
  NOR2_X1 U242 ( .A1(n225), .A2(n226), .ZN(n223) );
  NOR2_X1 U243 ( .A1(n227), .A2(n228), .ZN(n221) );
  NOR2_X1 U244 ( .A1(n229), .A2(n230), .ZN(n227) );
  NOR3_X1 U245 ( .A1(n228), .A2(n231), .A3(n224), .ZN(n215) );
  INV_X1 U246 ( .A(n232), .ZN(n224) );
  NOR2_X1 U247 ( .A1(n233), .A2(n234), .ZN(n231) );
  NOR2_X1 U248 ( .A1(n218), .A2(n219), .ZN(n234) );
  NOR2_X1 U249 ( .A1(n235), .A2(n220), .ZN(n233) );
  NOR2_X1 U250 ( .A1(n236), .A2(n237), .ZN(n235) );
  NOR2_X1 U251 ( .A1(n238), .A2(n218), .ZN(n237) );
  INV_X1 U252 ( .A(n239), .ZN(n218) );
  NOR2_X1 U253 ( .A1(n240), .A2(n241), .ZN(n238) );
  NOR2_X1 U254 ( .A1(n242), .A2(n219), .ZN(n236) );
  NOR2_X1 U255 ( .A1(n243), .A2(n244), .ZN(n242) );
  XOR2_X1 U256 ( .A(n245), .B(n246), .Z(G72) );
  XOR2_X1 U257 ( .A(n247), .B(n248), .Z(n246) );
  NOR2_X1 U258 ( .A1(n249), .A2(n250), .ZN(n248) );
  NOR2_X1 U259 ( .A1(n251), .A2(n252), .ZN(n249) );
  NAND2_X1 U260 ( .A1(n253), .A2(n254), .ZN(n247) );
  NAND2_X1 U261 ( .A1(G953), .A2(n252), .ZN(n254) );
  XOR2_X1 U262 ( .A(n255), .B(n256), .Z(n253) );
  NAND2_X1 U263 ( .A1(n250), .A2(n257), .ZN(n245) );
  XOR2_X1 U264 ( .A(n258), .B(n259), .Z(G69) );
  XOR2_X1 U265 ( .A(n260), .B(n261), .Z(n259) );
  NAND2_X1 U266 ( .A1(n262), .A2(n263), .ZN(n261) );
  NAND2_X1 U267 ( .A1(G953), .A2(n264), .ZN(n263) );
  NAND2_X1 U268 ( .A1(G953), .A2(n265), .ZN(n260) );
  NAND2_X1 U269 ( .A1(G898), .A2(G224), .ZN(n265) );
  NOR2_X1 U270 ( .A1(n212), .A2(G953), .ZN(n258) );
  NOR2_X1 U271 ( .A1(n266), .A2(n267), .ZN(G66) );
  XNOR2_X1 U272 ( .A(n268), .B(n269), .ZN(n267) );
  NOR2_X1 U273 ( .A1(n270), .A2(n271), .ZN(n269) );
  NOR2_X1 U274 ( .A1(n266), .A2(n272), .ZN(G63) );
  XNOR2_X1 U275 ( .A(n273), .B(n274), .ZN(n272) );
  NOR2_X1 U276 ( .A1(n275), .A2(n271), .ZN(n273) );
  NOR2_X1 U277 ( .A1(n266), .A2(n276), .ZN(G60) );
  XNOR2_X1 U278 ( .A(n277), .B(n278), .ZN(n276) );
  NOR2_X1 U279 ( .A1(n279), .A2(n271), .ZN(n278) );
  XNOR2_X1 U280 ( .A(G104), .B(n280), .ZN(G6) );
  NOR2_X1 U281 ( .A1(n266), .A2(n281), .ZN(G57) );
  XOR2_X1 U282 ( .A(n282), .B(n283), .Z(n281) );
  XOR2_X1 U283 ( .A(n284), .B(n285), .Z(n282) );
  NOR2_X1 U284 ( .A1(n286), .A2(n271), .ZN(n285) );
  NOR2_X1 U285 ( .A1(n266), .A2(n287), .ZN(G54) );
  XNOR2_X1 U286 ( .A(n288), .B(n289), .ZN(n287) );
  NOR2_X1 U287 ( .A1(n290), .A2(n271), .ZN(n289) );
  NOR2_X1 U288 ( .A1(n266), .A2(n291), .ZN(G51) );
  XNOR2_X1 U289 ( .A(n292), .B(n293), .ZN(n291) );
  NOR2_X1 U290 ( .A1(n294), .A2(n271), .ZN(n293) );
  NAND2_X1 U291 ( .A1(G902), .A2(n295), .ZN(n271) );
  NAND2_X1 U292 ( .A1(n212), .A2(n213), .ZN(n295) );
  INV_X1 U293 ( .A(n257), .ZN(n213) );
  NAND4_X1 U294 ( .A1(n296), .A2(n297), .A3(n298), .A4(n299), .ZN(n257) );
  NOR4_X1 U295 ( .A1(n300), .A2(n301), .A3(n302), .A4(n303), .ZN(n299) );
  NOR2_X1 U296 ( .A1(n304), .A2(n305), .ZN(n298) );
  AND2_X1 U297 ( .A1(n306), .A2(n307), .ZN(n212) );
  AND4_X1 U298 ( .A1(n308), .A2(n309), .A3(n310), .A4(n311), .ZN(n307) );
  AND4_X1 U299 ( .A1(n312), .A2(n313), .A3(n211), .A4(n280), .ZN(n306) );
  NAND3_X1 U300 ( .A1(n239), .A2(n314), .A3(n230), .ZN(n280) );
  NAND3_X1 U301 ( .A1(n239), .A2(n314), .A3(n229), .ZN(n211) );
  NOR2_X1 U302 ( .A1(n250), .A2(G952), .ZN(n266) );
  XNOR2_X1 U303 ( .A(G146), .B(n296), .ZN(G48) );
  NAND3_X1 U304 ( .A1(n230), .A2(n240), .A3(n315), .ZN(n296) );
  XNOR2_X1 U305 ( .A(G143), .B(n297), .ZN(G45) );
  NAND4_X1 U306 ( .A1(n316), .A2(n240), .A3(n317), .A4(n318), .ZN(n297) );
  XOR2_X1 U307 ( .A(G140), .B(n305), .Z(G42) );
  AND3_X1 U308 ( .A1(n319), .A2(n225), .A3(n320), .ZN(n305) );
  XOR2_X1 U309 ( .A(G137), .B(n304), .Z(G39) );
  AND3_X1 U310 ( .A1(n315), .A2(n232), .A3(n320), .ZN(n304) );
  XOR2_X1 U311 ( .A(G134), .B(n303), .Z(G36) );
  AND3_X1 U312 ( .A1(n316), .A2(n229), .A3(n320), .ZN(n303) );
  XOR2_X1 U313 ( .A(G131), .B(n302), .Z(G33) );
  AND3_X1 U314 ( .A1(n316), .A2(n230), .A3(n320), .ZN(n302) );
  INV_X1 U315 ( .A(n219), .ZN(n320) );
  NAND2_X1 U316 ( .A1(n241), .A2(n321), .ZN(n219) );
  NAND2_X1 U317 ( .A1(G214), .A2(n322), .ZN(n321) );
  AND3_X1 U318 ( .A1(n225), .A2(n323), .A3(n243), .ZN(n316) );
  XOR2_X1 U319 ( .A(G128), .B(n301), .Z(G30) );
  AND3_X1 U320 ( .A1(n229), .A2(n240), .A3(n315), .ZN(n301) );
  AND4_X1 U321 ( .A1(n225), .A2(n324), .A3(n325), .A4(n323), .ZN(n315) );
  XNOR2_X1 U322 ( .A(G101), .B(n313), .ZN(G3) );
  NAND3_X1 U323 ( .A1(n232), .A2(n314), .A3(n243), .ZN(n313) );
  XOR2_X1 U324 ( .A(G125), .B(n300), .Z(G27) );
  AND3_X1 U325 ( .A1(n326), .A2(n240), .A3(n319), .ZN(n300) );
  AND4_X1 U326 ( .A1(n244), .A2(n230), .A3(n324), .A4(n323), .ZN(n319) );
  NAND2_X1 U327 ( .A1(n327), .A2(n220), .ZN(n323) );
  NAND2_X1 U328 ( .A1(n328), .A2(n252), .ZN(n327) );
  INV_X1 U329 ( .A(G900), .ZN(n252) );
  XNOR2_X1 U330 ( .A(G122), .B(n312), .ZN(G24) );
  NAND4_X1 U331 ( .A1(n329), .A2(n239), .A3(n317), .A4(n318), .ZN(n312) );
  NOR2_X1 U332 ( .A1(n325), .A2(n324), .ZN(n239) );
  XNOR2_X1 U333 ( .A(G119), .B(n311), .ZN(G21) );
  NAND4_X1 U334 ( .A1(n329), .A2(n232), .A3(n324), .A4(n325), .ZN(n311) );
  XNOR2_X1 U335 ( .A(G116), .B(n310), .ZN(G18) );
  NAND3_X1 U336 ( .A1(n329), .A2(n229), .A3(n243), .ZN(n310) );
  NOR2_X1 U337 ( .A1(n318), .A2(n330), .ZN(n229) );
  XNOR2_X1 U338 ( .A(G113), .B(n309), .ZN(G15) );
  NAND3_X1 U339 ( .A1(n329), .A2(n230), .A3(n243), .ZN(n309) );
  NOR2_X1 U340 ( .A1(n324), .A2(n244), .ZN(n243) );
  AND2_X1 U341 ( .A1(n330), .A2(n318), .ZN(n230) );
  INV_X1 U342 ( .A(n317), .ZN(n330) );
  AND2_X1 U343 ( .A1(n326), .A2(n331), .ZN(n329) );
  INV_X1 U344 ( .A(n228), .ZN(n326) );
  NAND2_X1 U345 ( .A1(n226), .A2(n332), .ZN(n228) );
  NAND2_X1 U346 ( .A1(G221), .A2(n333), .ZN(n332) );
  XNOR2_X1 U347 ( .A(G110), .B(n308), .ZN(G12) );
  NAND4_X1 U348 ( .A1(n232), .A2(n314), .A3(n244), .A4(n324), .ZN(n308) );
  XOR2_X1 U349 ( .A(n334), .B(n270), .Z(n324) );
  NAND2_X1 U350 ( .A1(G217), .A2(n333), .ZN(n270) );
  NAND2_X1 U351 ( .A1(n268), .A2(n335), .ZN(n334) );
  XNOR2_X1 U352 ( .A(n336), .B(n337), .ZN(n268) );
  XOR2_X1 U353 ( .A(G119), .B(n338), .Z(n337) );
  XOR2_X1 U354 ( .A(G137), .B(G128), .Z(n338) );
  XOR2_X1 U355 ( .A(n339), .B(n340), .Z(n336) );
  XOR2_X1 U356 ( .A(G110), .B(n341), .Z(n340) );
  AND3_X1 U357 ( .A1(G221), .A2(n250), .A3(G234), .ZN(n341) );
  INV_X1 U358 ( .A(n325), .ZN(n244) );
  XOR2_X1 U359 ( .A(n342), .B(n286), .Z(n325) );
  INV_X1 U360 ( .A(G472), .ZN(n286) );
  NAND2_X1 U361 ( .A1(n343), .A2(n335), .ZN(n342) );
  XNOR2_X1 U362 ( .A(n284), .B(n283), .ZN(n343) );
  XNOR2_X1 U363 ( .A(n344), .B(G101), .ZN(n283) );
  NAND2_X1 U364 ( .A1(G210), .A2(n345), .ZN(n344) );
  XNOR2_X1 U365 ( .A(n255), .B(n346), .ZN(n284) );
  INV_X1 U366 ( .A(n347), .ZN(n346) );
  AND2_X1 U367 ( .A1(n225), .A2(n331), .ZN(n314) );
  AND2_X1 U368 ( .A1(n240), .A2(n348), .ZN(n331) );
  NAND2_X1 U369 ( .A1(n349), .A2(n220), .ZN(n348) );
  NAND3_X1 U370 ( .A1(n350), .A2(n250), .A3(G952), .ZN(n220) );
  NAND2_X1 U371 ( .A1(n328), .A2(n264), .ZN(n349) );
  INV_X1 U372 ( .A(G898), .ZN(n264) );
  AND3_X1 U373 ( .A1(G902), .A2(n350), .A3(G953), .ZN(n328) );
  NAND2_X1 U374 ( .A1(G237), .A2(G234), .ZN(n350) );
  NOR2_X1 U375 ( .A1(n241), .A2(n351), .ZN(n240) );
  AND2_X1 U376 ( .A1(G214), .A2(n322), .ZN(n351) );
  XNOR2_X1 U377 ( .A(n352), .B(n294), .ZN(n241) );
  NAND2_X1 U378 ( .A1(G210), .A2(n322), .ZN(n294) );
  NAND2_X1 U379 ( .A1(n353), .A2(n335), .ZN(n322) );
  INV_X1 U380 ( .A(G237), .ZN(n353) );
  NAND2_X1 U381 ( .A1(n292), .A2(n335), .ZN(n352) );
  XNOR2_X1 U382 ( .A(n354), .B(n355), .ZN(n292) );
  XOR2_X1 U383 ( .A(G125), .B(n356), .Z(n355) );
  AND2_X1 U384 ( .A1(n250), .A2(G224), .ZN(n356) );
  XOR2_X1 U385 ( .A(n262), .B(n357), .Z(n354) );
  XOR2_X1 U386 ( .A(n358), .B(n359), .Z(n262) );
  XOR2_X1 U387 ( .A(G122), .B(G110), .Z(n359) );
  XNOR2_X1 U388 ( .A(n347), .B(n360), .ZN(n358) );
  XOR2_X1 U389 ( .A(G113), .B(n361), .Z(n347) );
  XOR2_X1 U390 ( .A(G119), .B(G116), .Z(n361) );
  NOR2_X1 U391 ( .A1(n226), .A2(n362), .ZN(n225) );
  AND2_X1 U392 ( .A1(G221), .A2(n333), .ZN(n362) );
  NAND2_X1 U393 ( .A1(G234), .A2(n335), .ZN(n333) );
  XNOR2_X1 U394 ( .A(n363), .B(n290), .ZN(n226) );
  INV_X1 U395 ( .A(G469), .ZN(n290) );
  NAND2_X1 U396 ( .A1(n288), .A2(n335), .ZN(n363) );
  XNOR2_X1 U397 ( .A(n364), .B(n365), .ZN(n288) );
  XOR2_X1 U398 ( .A(n366), .B(n367), .Z(n365) );
  XOR2_X1 U399 ( .A(G140), .B(G110), .Z(n367) );
  NOR2_X1 U400 ( .A1(G953), .A2(n251), .ZN(n366) );
  INV_X1 U401 ( .A(G227), .ZN(n251) );
  XOR2_X1 U402 ( .A(n255), .B(n360), .Z(n364) );
  XOR2_X1 U403 ( .A(G101), .B(n368), .Z(n360) );
  XOR2_X1 U404 ( .A(G107), .B(G104), .Z(n368) );
  XOR2_X1 U405 ( .A(n369), .B(n370), .Z(n255) );
  XOR2_X1 U406 ( .A(G137), .B(G134), .Z(n370) );
  XNOR2_X1 U407 ( .A(n357), .B(G131), .ZN(n369) );
  XOR2_X1 U408 ( .A(G146), .B(n371), .Z(n357) );
  NOR2_X1 U409 ( .A1(n317), .A2(n318), .ZN(n232) );
  XOR2_X1 U410 ( .A(n372), .B(n279), .Z(n318) );
  INV_X1 U411 ( .A(G475), .ZN(n279) );
  NAND2_X1 U412 ( .A1(n277), .A2(n335), .ZN(n372) );
  XNOR2_X1 U413 ( .A(n373), .B(n374), .ZN(n277) );
  XOR2_X1 U414 ( .A(n375), .B(n376), .Z(n374) );
  XOR2_X1 U415 ( .A(G122), .B(G113), .Z(n376) );
  XNOR2_X1 U416 ( .A(n377), .B(G131), .ZN(n375) );
  INV_X1 U417 ( .A(G143), .ZN(n377) );
  XOR2_X1 U418 ( .A(n339), .B(n378), .Z(n373) );
  XNOR2_X1 U419 ( .A(G104), .B(n379), .ZN(n378) );
  NAND2_X1 U420 ( .A1(G214), .A2(n345), .ZN(n379) );
  NOR2_X1 U421 ( .A1(G953), .A2(G237), .ZN(n345) );
  XNOR2_X1 U422 ( .A(G146), .B(n256), .ZN(n339) );
  XOR2_X1 U423 ( .A(G125), .B(G140), .Z(n256) );
  XOR2_X1 U424 ( .A(n380), .B(n275), .Z(n317) );
  INV_X1 U425 ( .A(G478), .ZN(n275) );
  NAND2_X1 U426 ( .A1(n274), .A2(n335), .ZN(n380) );
  INV_X1 U427 ( .A(G902), .ZN(n335) );
  NAND2_X1 U428 ( .A1(n381), .A2(n382), .ZN(n274) );
  NAND2_X1 U429 ( .A1(n383), .A2(n384), .ZN(n382) );
  NAND3_X1 U430 ( .A1(G217), .A2(n250), .A3(G234), .ZN(n384) );
  NAND4_X1 U431 ( .A1(G217), .A2(n250), .A3(G234), .A4(n385), .ZN(n381) );
  INV_X1 U432 ( .A(n383), .ZN(n385) );
  XNOR2_X1 U433 ( .A(n386), .B(n387), .ZN(n383) );
  XOR2_X1 U434 ( .A(G116), .B(n388), .Z(n387) );
  XOR2_X1 U435 ( .A(G134), .B(G122), .Z(n388) );
  XNOR2_X1 U436 ( .A(G107), .B(n371), .ZN(n386) );
  XOR2_X1 U437 ( .A(G128), .B(G143), .Z(n371) );
  INV_X1 U438 ( .A(G953), .ZN(n250) );
endmodule

