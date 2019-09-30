S = input()
N = int(input())
for i in range(N):
    l, r = map(int, input().split())
    a = S[l-1:r]
    b = a[::-1]
    S = S[:l-1] + b + S[r:]
print(S)