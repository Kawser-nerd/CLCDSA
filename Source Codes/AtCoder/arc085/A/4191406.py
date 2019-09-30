n,m = map(int,input().split())

summation = m*1900 + (n-m)*100
ans = summation*(2**m)
print(ans)