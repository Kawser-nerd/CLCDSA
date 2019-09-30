main(a){gets(&a);puts(9*17*29*13*23%(a-88)?"consonant":"vowel");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(a){gets(&a);puts(9*17*29*13*23%(a-88)?"consonant":"vowel");}
 ^
./Main.c: In function ‘main’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:9: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
 main(a){gets(&a);puts(9*17*29*13*23%(a-88)?"consonant":"vowel");}
         ^
./Main.c:1:18: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 main(a){gets(&a);puts(9*17*29*13*23%(a-88)?"consonant":"vowel");}
                  ^
/tmp/ccW9ow9N.o: In function `main':
Main.c:(.text.startup+0x10): warning: the `gets' function is dangerous and should not be used.