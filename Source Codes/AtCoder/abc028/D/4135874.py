N,K = map(int,input().split())
left = K-1
right = N - K
num1 = left*right * 6
num2 = (left+right) * 3
num3 = 1
ans = (num1 + num2 + num3) / pow(N,3)
print(ans)