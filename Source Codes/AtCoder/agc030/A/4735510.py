A,B,C = map(int,input().split())

ans = min(C, A+B+1)
ans += B
print(ans)