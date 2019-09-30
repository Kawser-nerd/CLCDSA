w,a,b = map(int,input().split())
print(max(max(a,b) - min(a,b) - w, 0))