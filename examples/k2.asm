mov $a,3; // REG[A] = 3
mov $b,5; // REG[B] = 5
addr $a,$b,$c; // REG[C] = REG[A] + REG[B]
addv 5,5,$a; // REG[A] = 5 + 5
print $c; // PRINT REG[C] => RESULT : 8
