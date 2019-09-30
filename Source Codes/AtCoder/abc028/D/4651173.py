n,k = map(int, input().split())
patot = 1 + (n-1)*3 + (k-1)*(n-k)*6
print(patot/n**3)