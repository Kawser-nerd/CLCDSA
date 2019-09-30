k,s=map(int,input().split())
print(len([1 for z in range(k+1) for y in range(k+1) if 0<=s-y-z<=k]))