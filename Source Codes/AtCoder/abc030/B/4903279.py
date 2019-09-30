n,m=map(int,input().split())
print(min(abs(11*m/2-30*(n%12)),abs(360-abs(11*m/2-30*(n%12)))))