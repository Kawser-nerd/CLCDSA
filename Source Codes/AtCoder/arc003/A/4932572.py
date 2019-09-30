n=int(input())
gm={'A': 4,'B':3,'C':2,'D':1,'F':0}
print(sum(gm[r] for r in input().strip())/n)