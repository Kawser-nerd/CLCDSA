def iv(d,p):
    return (d[0]//p[0]) * (d[1]//p[1]) * (d[2]//p[2])
D = list(map(int,input().split()))
P,Q,R = map(int,input().split())
print(max(iv(D,[P,Q,R]),iv(D,[P,R,Q]),iv(D,[Q,R,P]),
          iv(D,[Q,P,R]),iv(D,[R,P,Q]),iv(D,[R,Q,P])))