import sys

def generuj(n, i, predesle):
    if (i == n):
        return [n]
    #predesle = generuj(n,i+1)
    pozice = i % (n-i+1)
    if pozice==0:
        pozice = (n-i+1)
    zbyva = (n-i+1) - pozice
    konec = predesle[0:zbyva]
    zacatek = predesle[zbyva:]
    return zacatek + [i] + konec

def vygeneruj(n):
    data = []
    for i in range(n,0,-1):
        predesle = data
        data = generuj(n,i,predesle)
    return data


sys.stdin.readline()

case = 1
while 1:
    line = sys.stdin.readline()
    if line=='':
        break
    n = int(line)
    balicek = vygeneruj(n)
    #print n, balicek
    data = [int (i) for i in sys.stdin.readline().split()]
    #print data

    print "Case #%d:" % case,
    print " ".join([str(balicek[i-1]) for i in data[1:]])

    case += 1


