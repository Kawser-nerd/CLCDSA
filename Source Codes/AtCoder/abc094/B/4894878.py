n,m,x = map(int,input().split())
a = [ int(i) for i in input().split() ]
import bisect
a = sorted(a)
cn1 = bisect.bisect_left(a,x)
cn2 = len(a) - cn1
print(min(cn1,cn2))