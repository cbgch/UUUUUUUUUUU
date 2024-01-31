/////////////////////////////////////////////////////////////
// Created by: Synopsys DC Expert(TM) in wire load mode
// Version   : L-2016.03-SP1
// Date      : Wed Jan 10 17:48:46 2024
/////////////////////////////////////////////////////////////


module c1355 ( G1gat, G8gat, G15gat, G22gat, G29gat, G36gat, G43gat, G50gat, 
        G57gat, G64gat, G71gat, G78gat, G85gat, G92gat, G99gat, G106gat, 
        G113gat, G120gat, G127gat, G134gat, G141gat, G148gat, G155gat, G162gat, 
        G169gat, G176gat, G183gat, G190gat, G197gat, G204gat, G211gat, G218gat, 
        G225gat, G226gat, G227gat, G228gat, G229gat, G230gat, G231gat, G232gat, 
        G233gat, G1324gat, G1325gat, G1326gat, G1327gat, G1328gat, G1329gat, 
        G1330gat, G1331gat, G1332gat, G1333gat, G1334gat, G1335gat, G1336gat, 
        G1337gat, G1338gat, G1339gat, G1340gat, G1341gat, G1342gat, G1343gat, 
        G1344gat, G1345gat, G1346gat, G1347gat, G1348gat, G1349gat, G1350gat, 
        G1351gat, G1352gat, G1353gat, G1354gat, G1355gat );
  input G1gat, G8gat, G15gat, G22gat, G29gat, G36gat, G43gat, G50gat, G57gat,
         G64gat, G71gat, G78gat, G85gat, G92gat, G99gat, G106gat, G113gat,
         G120gat, G127gat, G134gat, G141gat, G148gat, G155gat, G162gat,
         G169gat, G176gat, G183gat, G190gat, G197gat, G204gat, G211gat,
         G218gat, G225gat, G226gat, G227gat, G228gat, G229gat, G230gat,
         G231gat, G232gat, G233gat;
  output G1324gat, G1325gat, G1326gat, G1327gat, G1328gat, G1329gat, G1330gat,
         G1331gat, G1332gat, G1333gat, G1334gat, G1335gat, G1336gat, G1337gat,
         G1338gat, G1339gat, G1340gat, G1341gat, G1342gat, G1343gat, G1344gat,
         G1345gat, G1346gat, G1347gat, G1348gat, G1349gat, G1350gat, G1351gat,
         G1352gat, G1353gat, G1354gat, G1355gat;
  wire   n287, n288, n289, n290, n291, n292, n293, n294, n295, n296, n297,
         n298, n299, n300, n301, n302, n303, n304, n305, n306, n307, n308,
         n309, n310, n311, n312, n313, n314, n315, n316, n317, n318, n319,
         n320, n321, n322, n323, n324, n325, n326, n327, n328, n329, n330,
         n331, n332, n333, n334, n335, n336, n337, n338, n339, n340, n341,
         n342, n343, n344, n345, n346, n347, n348, n349, n350, n351, n352,
         n353, n354, n355, n356, n357, n358, n359, n360, n361, n362, n363,
         n364, n365, n366, n367, n368, n369, n370, n371, n372, n373, n374,
         n375, n376, n377, n378, n379, n380, n381, n382, n383, n384, n385,
         n386, n387, n388, n389, n390, n391, n392, n393, n394, n395, n396,
         n397, n398, n399, n400, n401, n402, n403, n404, n405, n406, n407,
         n408, n409, n410, n411, n412, n413, n414, n415, n416, n417, n418,
         n419, n420, n421, n422, n423, n424, n425, n426, n427, n428, n429,
         n430, n431, n432, n433, n434, n435, n436, n437, n438, n439, n440,
         n441, n442, n443, n444, n445, n446, n447, n448, n449, n450, n451,
         n452, n453, n454, n455, n456, n457, n458, n459, n460, n461, n462,
         n463, n464, n465;
  XOR2_X1 U319 ( .A(G218gat), .B(n287), .Z(G1355gat) );
  NOR2_X1 U320 ( .A1(n288), .A2(n289), .ZN(n287) );
  XOR2_X1 U321 ( .A(G211gat), .B(n290), .Z(G1354gat) );
  NOR2_X1 U322 ( .A1(n291), .A2(n289), .ZN(n290) );
  XOR2_X1 U323 ( .A(G204gat), .B(n292), .Z(G1353gat) );
  NOR2_X1 U324 ( .A1(n293), .A2(n289), .ZN(n292) );
  XOR2_X1 U325 ( .A(G197gat), .B(n294), .Z(G1352gat) );
  NOR2_X1 U326 ( .A1(n295), .A2(n289), .ZN(n294) );
  NAND4_X1 U327 ( .A1(n296), .A2(n297), .A3(n298), .A4(n299), .ZN(n289) );
  XOR2_X1 U328 ( .A(G190gat), .B(n300), .Z(G1351gat) );
  NOR2_X1 U329 ( .A1(n288), .A2(n301), .ZN(n300) );
  XOR2_X1 U330 ( .A(G183gat), .B(n302), .Z(G1350gat) );
  NOR2_X1 U331 ( .A1(n291), .A2(n301), .ZN(n302) );
  XOR2_X1 U332 ( .A(G176gat), .B(n303), .Z(G1349gat) );
  NOR2_X1 U333 ( .A1(n293), .A2(n301), .ZN(n303) );
  XOR2_X1 U334 ( .A(G169gat), .B(n304), .Z(G1348gat) );
  NOR2_X1 U335 ( .A1(n295), .A2(n301), .ZN(n304) );
  NAND4_X1 U336 ( .A1(n305), .A2(n299), .A3(n306), .A4(n307), .ZN(n301) );
  NOR2_X1 U337 ( .A1(n308), .A2(n309), .ZN(n307) );
  XOR2_X1 U338 ( .A(G162gat), .B(n310), .Z(G1347gat) );
  NOR2_X1 U339 ( .A1(n288), .A2(n311), .ZN(n310) );
  XNOR2_X1 U340 ( .A(n312), .B(n313), .ZN(G1346gat) );
  NOR2_X1 U341 ( .A1(n291), .A2(n311), .ZN(n313) );
  XOR2_X1 U342 ( .A(G148gat), .B(n314), .Z(G1345gat) );
  NOR2_X1 U343 ( .A1(n293), .A2(n311), .ZN(n314) );
  XOR2_X1 U344 ( .A(G141gat), .B(n315), .Z(G1344gat) );
  NOR2_X1 U345 ( .A1(n295), .A2(n311), .ZN(n315) );
  NAND4_X1 U346 ( .A1(n308), .A2(n299), .A3(n309), .A4(n316), .ZN(n311) );
  NOR2_X1 U347 ( .A1(n306), .A2(n305), .ZN(n316) );
  XOR2_X1 U348 ( .A(G134gat), .B(n317), .Z(G1343gat) );
  NOR2_X1 U349 ( .A1(n288), .A2(n318), .ZN(n317) );
  XNOR2_X1 U350 ( .A(n319), .B(n320), .ZN(G1342gat) );
  NOR2_X1 U351 ( .A1(n291), .A2(n318), .ZN(n320) );
  XOR2_X1 U352 ( .A(G120gat), .B(n321), .Z(G1341gat) );
  NOR2_X1 U353 ( .A1(n293), .A2(n318), .ZN(n321) );
  XOR2_X1 U354 ( .A(G113gat), .B(n322), .Z(G1340gat) );
  NOR2_X1 U355 ( .A1(n295), .A2(n318), .ZN(n322) );
  NAND4_X1 U356 ( .A1(n323), .A2(n324), .A3(n325), .A4(n299), .ZN(n318) );
  NAND2_X1 U357 ( .A1(n326), .A2(n327), .ZN(n299) );
  OR3_X1 U358 ( .A1(n328), .A2(n329), .A3(n330), .ZN(n327) );
  OR3_X1 U359 ( .A1(n331), .A2(n332), .A3(n333), .ZN(n326) );
  XOR2_X1 U360 ( .A(G106gat), .B(n334), .Z(G1339gat) );
  NOR2_X1 U361 ( .A1(n325), .A2(n335), .ZN(n334) );
  XOR2_X1 U362 ( .A(G99gat), .B(n336), .Z(G1338gat) );
  NOR2_X1 U363 ( .A1(n296), .A2(n335), .ZN(n336) );
  XOR2_X1 U364 ( .A(G92gat), .B(n337), .Z(G1337gat) );
  NOR2_X1 U365 ( .A1(n323), .A2(n335), .ZN(n337) );
  XOR2_X1 U366 ( .A(G85gat), .B(n338), .Z(G1336gat) );
  NOR2_X1 U367 ( .A1(n298), .A2(n335), .ZN(n338) );
  NAND4_X1 U368 ( .A1(n291), .A2(n332), .A3(n295), .A4(n339), .ZN(n335) );
  NOR2_X1 U369 ( .A1(n288), .A2(n293), .ZN(n332) );
  XOR2_X1 U370 ( .A(G78gat), .B(n340), .Z(G1335gat) );
  NOR2_X1 U371 ( .A1(n325), .A2(n341), .ZN(n340) );
  XOR2_X1 U372 ( .A(G71gat), .B(n342), .Z(G1334gat) );
  NOR2_X1 U373 ( .A1(n296), .A2(n341), .ZN(n342) );
  XOR2_X1 U374 ( .A(G64gat), .B(n343), .Z(G1333gat) );
  NOR2_X1 U375 ( .A1(n323), .A2(n341), .ZN(n343) );
  XNOR2_X1 U376 ( .A(n344), .B(n345), .ZN(G1332gat) );
  NOR2_X1 U377 ( .A1(n298), .A2(n341), .ZN(n345) );
  NAND4_X1 U378 ( .A1(n333), .A2(n339), .A3(n330), .A4(n346), .ZN(n341) );
  NOR2_X1 U379 ( .A1(n328), .A2(n331), .ZN(n346) );
  XOR2_X1 U380 ( .A(G50gat), .B(n347), .Z(G1331gat) );
  NOR2_X1 U381 ( .A1(n325), .A2(n348), .ZN(n347) );
  XNOR2_X1 U382 ( .A(n349), .B(n350), .ZN(G1330gat) );
  NOR2_X1 U383 ( .A1(n296), .A2(n348), .ZN(n350) );
  XOR2_X1 U384 ( .A(G36gat), .B(n351), .Z(G1329gat) );
  NOR2_X1 U385 ( .A1(n323), .A2(n348), .ZN(n351) );
  XOR2_X1 U386 ( .A(G29gat), .B(n352), .Z(G1328gat) );
  NOR2_X1 U387 ( .A1(n298), .A2(n348), .ZN(n352) );
  NAND4_X1 U388 ( .A1(n331), .A2(n339), .A3(n328), .A4(n353), .ZN(n348) );
  NOR2_X1 U389 ( .A1(n333), .A2(n330), .ZN(n353) );
  XOR2_X1 U390 ( .A(G22gat), .B(n354), .Z(G1327gat) );
  NOR2_X1 U391 ( .A1(n325), .A2(n355), .ZN(n354) );
  XOR2_X1 U392 ( .A(G15gat), .B(n356), .Z(G1326gat) );
  NOR2_X1 U393 ( .A1(n296), .A2(n355), .ZN(n356) );
  XOR2_X1 U394 ( .A(G8gat), .B(n357), .Z(G1325gat) );
  NOR2_X1 U395 ( .A1(n323), .A2(n355), .ZN(n357) );
  XOR2_X1 U396 ( .A(G1gat), .B(n358), .Z(G1324gat) );
  NOR2_X1 U397 ( .A1(n298), .A2(n355), .ZN(n358) );
  NAND4_X1 U398 ( .A1(n293), .A2(n329), .A3(n288), .A4(n339), .ZN(n355) );
  NAND2_X1 U399 ( .A1(n359), .A2(n360), .ZN(n339) );
  OR3_X1 U400 ( .A1(n308), .A2(n324), .A3(n305), .ZN(n360) );
  NOR2_X1 U401 ( .A1(n298), .A2(n296), .ZN(n324) );
  INV_X1 U402 ( .A(n306), .ZN(n296) );
  OR3_X1 U403 ( .A1(n309), .A2(n297), .A3(n306), .ZN(n359) );
  XNOR2_X1 U404 ( .A(n361), .B(n362), .ZN(n306) );
  XNOR2_X1 U405 ( .A(G15gat), .B(n363), .ZN(n362) );
  NAND2_X1 U406 ( .A1(n364), .A2(n365), .ZN(n363) );
  NAND3_X1 U407 ( .A1(G233gat), .A2(n366), .A3(G227gat), .ZN(n365) );
  XNOR2_X1 U408 ( .A(n367), .B(n368), .ZN(n366) );
  NAND2_X1 U409 ( .A1(n369), .A2(n370), .ZN(n364) );
  NAND2_X1 U410 ( .A1(G227gat), .A2(G233gat), .ZN(n370) );
  XNOR2_X1 U411 ( .A(n368), .B(n371), .ZN(n369) );
  XNOR2_X1 U412 ( .A(G43gat), .B(n372), .ZN(n361) );
  XOR2_X1 U413 ( .A(G99gat), .B(G71gat), .Z(n372) );
  NOR2_X1 U414 ( .A1(n323), .A2(n325), .ZN(n297) );
  INV_X1 U415 ( .A(n308), .ZN(n325) );
  XNOR2_X1 U416 ( .A(n373), .B(n374), .ZN(n308) );
  XNOR2_X1 U417 ( .A(G106gat), .B(n375), .ZN(n374) );
  NAND2_X1 U418 ( .A1(n376), .A2(n377), .ZN(n375) );
  NAND3_X1 U419 ( .A1(G233gat), .A2(n378), .A3(G228gat), .ZN(n377) );
  XNOR2_X1 U420 ( .A(n379), .B(n380), .ZN(n378) );
  NAND2_X1 U421 ( .A1(n381), .A2(n382), .ZN(n376) );
  NAND2_X1 U422 ( .A1(G228gat), .A2(G233gat), .ZN(n382) );
  XNOR2_X1 U423 ( .A(n383), .B(n379), .ZN(n381) );
  XNOR2_X1 U424 ( .A(G22gat), .B(n384), .ZN(n373) );
  XOR2_X1 U425 ( .A(G78gat), .B(G50gat), .Z(n384) );
  INV_X1 U426 ( .A(n305), .ZN(n323) );
  XNOR2_X1 U427 ( .A(n385), .B(n386), .ZN(n305) );
  XNOR2_X1 U428 ( .A(G36gat), .B(n387), .ZN(n386) );
  NAND2_X1 U429 ( .A1(n388), .A2(n389), .ZN(n387) );
  NAND3_X1 U430 ( .A1(G233gat), .A2(n390), .A3(G226gat), .ZN(n389) );
  XNOR2_X1 U431 ( .A(n368), .B(n380), .ZN(n390) );
  INV_X1 U432 ( .A(n383), .ZN(n380) );
  NAND2_X1 U433 ( .A1(n391), .A2(n392), .ZN(n388) );
  NAND2_X1 U434 ( .A1(G226gat), .A2(G233gat), .ZN(n392) );
  XNOR2_X1 U435 ( .A(n383), .B(n368), .ZN(n391) );
  XNOR2_X1 U436 ( .A(n393), .B(n394), .ZN(n368) );
  XOR2_X1 U437 ( .A(G190gat), .B(G183gat), .Z(n394) );
  XNOR2_X1 U438 ( .A(G169gat), .B(G176gat), .ZN(n393) );
  XNOR2_X1 U439 ( .A(n395), .B(n396), .ZN(n383) );
  XOR2_X1 U440 ( .A(G218gat), .B(G211gat), .Z(n396) );
  XNOR2_X1 U441 ( .A(G197gat), .B(G204gat), .ZN(n395) );
  XNOR2_X1 U442 ( .A(G64gat), .B(n397), .ZN(n385) );
  XOR2_X1 U443 ( .A(G92gat), .B(G8gat), .Z(n397) );
  INV_X1 U444 ( .A(n328), .ZN(n288) );
  XNOR2_X1 U445 ( .A(n398), .B(n399), .ZN(n328) );
  XNOR2_X1 U446 ( .A(G134gat), .B(n400), .ZN(n399) );
  NAND2_X1 U447 ( .A1(n401), .A2(n402), .ZN(n400) );
  NAND3_X1 U448 ( .A1(G233gat), .A2(n403), .A3(G232gat), .ZN(n402) );
  XOR2_X1 U449 ( .A(n404), .B(n405), .Z(n403) );
  NAND2_X1 U450 ( .A1(n406), .A2(n407), .ZN(n401) );
  NAND2_X1 U451 ( .A1(G232gat), .A2(G233gat), .ZN(n407) );
  XNOR2_X1 U452 ( .A(n405), .B(n404), .ZN(n406) );
  XNOR2_X1 U453 ( .A(G162gat), .B(n408), .ZN(n398) );
  XOR2_X1 U454 ( .A(G218gat), .B(G190gat), .Z(n408) );
  NOR2_X1 U455 ( .A1(n295), .A2(n291), .ZN(n329) );
  INV_X1 U456 ( .A(n333), .ZN(n291) );
  XNOR2_X1 U457 ( .A(n409), .B(n410), .ZN(n333) );
  XNOR2_X1 U458 ( .A(G127gat), .B(n411), .ZN(n410) );
  NAND2_X1 U459 ( .A1(n412), .A2(n413), .ZN(n411) );
  NAND3_X1 U460 ( .A1(G231gat), .A2(n414), .A3(G233gat), .ZN(n413) );
  XNOR2_X1 U461 ( .A(n415), .B(n416), .ZN(n414) );
  NAND2_X1 U462 ( .A1(n417), .A2(n418), .ZN(n412) );
  NAND2_X1 U463 ( .A1(G233gat), .A2(G231gat), .ZN(n418) );
  XNOR2_X1 U464 ( .A(n419), .B(n415), .ZN(n417) );
  XNOR2_X1 U465 ( .A(G155gat), .B(n420), .ZN(n409) );
  XOR2_X1 U466 ( .A(G211gat), .B(G183gat), .Z(n420) );
  INV_X1 U467 ( .A(n331), .ZN(n295) );
  NAND2_X1 U468 ( .A1(n421), .A2(n422), .ZN(n331) );
  NAND2_X1 U469 ( .A1(n423), .A2(n424), .ZN(n422) );
  NAND2_X1 U470 ( .A1(n425), .A2(n426), .ZN(n424) );
  NAND3_X1 U471 ( .A1(n425), .A2(n426), .A3(n427), .ZN(n421) );
  INV_X1 U472 ( .A(n423), .ZN(n427) );
  XNOR2_X1 U473 ( .A(n428), .B(n429), .ZN(n423) );
  XOR2_X1 U474 ( .A(G197gat), .B(G169gat), .Z(n429) );
  XNOR2_X1 U475 ( .A(G113gat), .B(G141gat), .ZN(n428) );
  NAND2_X1 U476 ( .A1(n430), .A2(n431), .ZN(n426) );
  NAND2_X1 U477 ( .A1(G229gat), .A2(G233gat), .ZN(n431) );
  XNOR2_X1 U478 ( .A(n419), .B(n405), .ZN(n430) );
  NAND3_X1 U479 ( .A1(G233gat), .A2(n432), .A3(G229gat), .ZN(n425) );
  XNOR2_X1 U480 ( .A(n405), .B(n416), .ZN(n432) );
  INV_X1 U481 ( .A(n419), .ZN(n416) );
  XNOR2_X1 U482 ( .A(n433), .B(n434), .ZN(n419) );
  XOR2_X1 U483 ( .A(G8gat), .B(G22gat), .Z(n434) );
  XNOR2_X1 U484 ( .A(G15gat), .B(G1gat), .ZN(n433) );
  XNOR2_X1 U485 ( .A(n435), .B(n436), .ZN(n405) );
  XNOR2_X1 U486 ( .A(G50gat), .B(n349), .ZN(n436) );
  INV_X1 U487 ( .A(G43gat), .ZN(n349) );
  XNOR2_X1 U488 ( .A(G29gat), .B(G36gat), .ZN(n435) );
  INV_X1 U489 ( .A(n330), .ZN(n293) );
  XNOR2_X1 U490 ( .A(n437), .B(n438), .ZN(n330) );
  XNOR2_X1 U491 ( .A(G120gat), .B(n439), .ZN(n438) );
  NAND2_X1 U492 ( .A1(n440), .A2(n441), .ZN(n439) );
  NAND3_X1 U493 ( .A1(G233gat), .A2(n442), .A3(G230gat), .ZN(n441) );
  XOR2_X1 U494 ( .A(n404), .B(n415), .Z(n442) );
  NAND2_X1 U495 ( .A1(n443), .A2(n444), .ZN(n440) );
  NAND2_X1 U496 ( .A1(G230gat), .A2(G233gat), .ZN(n444) );
  XNOR2_X1 U497 ( .A(n415), .B(n404), .ZN(n443) );
  XNOR2_X1 U498 ( .A(n445), .B(n446), .ZN(n404) );
  XOR2_X1 U499 ( .A(G99gat), .B(G92gat), .Z(n446) );
  XNOR2_X1 U500 ( .A(G106gat), .B(G85gat), .ZN(n445) );
  XNOR2_X1 U501 ( .A(n447), .B(n448), .ZN(n415) );
  XOR2_X1 U502 ( .A(G78gat), .B(G71gat), .Z(n448) );
  XNOR2_X1 U503 ( .A(G57gat), .B(G64gat), .ZN(n447) );
  XNOR2_X1 U504 ( .A(G148gat), .B(n449), .ZN(n437) );
  XOR2_X1 U505 ( .A(G204gat), .B(G176gat), .Z(n449) );
  INV_X1 U506 ( .A(n309), .ZN(n298) );
  NAND2_X1 U507 ( .A1(n450), .A2(n451), .ZN(n309) );
  NAND2_X1 U508 ( .A1(n452), .A2(n453), .ZN(n451) );
  NAND2_X1 U509 ( .A1(n454), .A2(n455), .ZN(n453) );
  NAND3_X1 U510 ( .A1(n454), .A2(n455), .A3(n456), .ZN(n450) );
  INV_X1 U511 ( .A(n452), .ZN(n456) );
  XNOR2_X1 U512 ( .A(n457), .B(n458), .ZN(n452) );
  XNOR2_X1 U513 ( .A(G85gat), .B(n344), .ZN(n458) );
  INV_X1 U514 ( .A(G57gat), .ZN(n344) );
  XNOR2_X1 U515 ( .A(G1gat), .B(G29gat), .ZN(n457) );
  NAND2_X1 U516 ( .A1(n459), .A2(n460), .ZN(n455) );
  NAND2_X1 U517 ( .A1(G225gat), .A2(G233gat), .ZN(n460) );
  XNOR2_X1 U518 ( .A(n371), .B(n379), .ZN(n459) );
  NAND3_X1 U519 ( .A1(G233gat), .A2(n461), .A3(G225gat), .ZN(n454) );
  XNOR2_X1 U520 ( .A(n379), .B(n367), .ZN(n461) );
  INV_X1 U521 ( .A(n371), .ZN(n367) );
  XNOR2_X1 U522 ( .A(n462), .B(n463), .ZN(n371) );
  XNOR2_X1 U523 ( .A(G134gat), .B(n319), .ZN(n463) );
  INV_X1 U524 ( .A(G127gat), .ZN(n319) );
  XNOR2_X1 U525 ( .A(G113gat), .B(G120gat), .ZN(n462) );
  XNOR2_X1 U526 ( .A(n464), .B(n465), .ZN(n379) );
  XNOR2_X1 U527 ( .A(G162gat), .B(n312), .ZN(n465) );
  INV_X1 U528 ( .A(G155gat), .ZN(n312) );
  XNOR2_X1 U529 ( .A(G141gat), .B(G148gat), .ZN(n464) );
endmodule

