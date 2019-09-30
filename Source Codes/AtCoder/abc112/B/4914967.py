N,T=map(int, input().split())
m = min([c if t <= T else 9999 for c,t in [map(int, input().split()) for _ in range(N)]])
print("TLE" if m==9999 else m)