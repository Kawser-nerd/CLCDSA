n,k = map(int,input().split())
a = [ int(i) for i in input().split() ]
a = sorted(a)
print( sum( a[-k:] ) )