N = int(input())

for i in range(1,N+1):
    if i * i <= N:
        if N % i == 0:
            ans = i
    else:
        break
print(len(str(N // ans)))