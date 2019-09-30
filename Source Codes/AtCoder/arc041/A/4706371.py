ox,uy = map(int,input().split())
K = int(input())
if uy >= K:ox += K
else:ox = ox - (K-uy) + uy
print(ox)