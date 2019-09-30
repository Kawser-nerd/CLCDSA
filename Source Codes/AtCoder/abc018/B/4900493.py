S = [i for i in input()]
N = int(input())
for i in range(N):
    l,m = map(int,input().split())
    S=S[:l-1]+S[l-1:m][::-1]+S[m:]
print("".join(S))