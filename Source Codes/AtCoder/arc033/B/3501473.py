n,m = map(int,input().split())
k = len(set(list(map(int,input().split())))&set(list(map(int,input().split()))))
print(k/(n+m-k))