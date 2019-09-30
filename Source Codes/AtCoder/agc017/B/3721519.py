N, A, B, C, D = map(int, input().split())

for i in range(N-1):
    if C * (N-1-i) - D*i <= B-A <= D*(N-1-i) - C*i:
        print("YES")
        break
else: print("NO")