a,b,k,l = map(int,input().split())
ans = min((k % l)*a + (k // l)*b, (k // l + 1 ) * b)
print(ans)