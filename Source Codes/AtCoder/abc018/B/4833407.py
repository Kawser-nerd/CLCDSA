S = input()
N = int(input())

for i in range(N):
    l, r = map(int, input().split())
    S = S[:l-1] + S[l-1:r][::-1] + S[r:]

print(S)