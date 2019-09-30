aaa = list(map(int,input().split()))
aaa.sort()
ans = aaa[2] * 10 + aaa[1] + aaa[0]
print(ans)