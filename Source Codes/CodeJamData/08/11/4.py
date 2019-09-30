from __future__ import division
from operator import itemgetter


def main():
    entrada=open('A-large.in', 'r')
    saida=open('y.out','w')
    casos = int(entrada.readline())
    
    for caso in range(1,casos+1):
        numeros = int(entrada.readline())
        a = entrada.readline().split()
        b = entrada.readline().split()

        c = []
        d = []

        for x in a:
            c.append(int(x))

        for x in b:
            d.append(int(x))

        d.sort()
        c.sort(reverse=True)

        resultado = 0
        for i in range(len(d)):
            resultado += d[i]*c[i]
            
        saida.write("Case #%i: %i\n" % (caso, resultado) )

    entrada.close()
    saida.close()
    print "Tchau e obrigado pelos peixes!"

main()
