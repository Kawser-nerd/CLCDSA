from __future__ import division
from operator import itemgetter
from math import sqrt
from mpmath import *

def main():
    entrada=open('C-large.in', 'r')
    saida=open('grade.out','w')
    casos = int(entrada.readline())
    mp.dps = 100
    calculo = ['143', '751', '935', '607', '903', '991', '335', '047', '943', '471', '055', '447', '463', '991', '095', '607', '263', '151', '855', '527', '743', '351', '135', '407', '903', '791', '135', '647', '343', '471', '455', '847', '263', '191', '095', '807', '463', '551', '455', '527', '343', '951', '335', '207', '903', '591', '935', '247', '743', '471', '855', '247', '063', '391', '095', '007', '663', '951', '055', '527', '943', '551', '535', '007', '903', '391', '735', '847', '143', '471', '255', '647', '863', '591', '095', '207', '863', '351', '655', '527', '543', '151', '735', '807', '903', '191', '535', '447', '543', '471', '655', '047', '663', '791', '095', '407', '063', '751', '255', '527']
    
    for caso in range(1,casos+1):
        numero = int(entrada.readline())

        if numero == 0:
                saida.write("Case #%i: 001\n" % (caso) )
                continue
                
        if numero == 1:
                saida.write("Case #%i: 005\n" % (caso) )
                continue
                
        if numero == 2:
                saida.write("Case #%i: 027\n" % (caso) )
                continue

        print calculo[numero%len(calculo)-3]
        saida.write("Case #%i: %s\n" % (caso, calculo[numero%len(calculo)-3] ) )
                
                
    entrada.close()
    saida.close()
    print "Tchau e obrigado pelos peixes!"

main()
