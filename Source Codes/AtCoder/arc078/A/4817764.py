N = int(input())
A = [int(a) for a in input().split()]

S = [0]
for a in A:
  S.append(S[-1]+a)

Min = 10**20
for i in range(1,N):
  Min = min(Min,abs((S[i]-S[0])-(S[N]-S[i])))
print(Min)