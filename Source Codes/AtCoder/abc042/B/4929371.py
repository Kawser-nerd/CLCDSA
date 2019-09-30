N, L = map(int, input().split())
S =[]
for _ in range(N):
    S.append(input()) 
x = ''.join(sorted(S))
print(x)