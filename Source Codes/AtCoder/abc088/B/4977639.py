N = int(input())
Ai = input().split()
Ai = [int(n) for n in Ai]
Ai = sorted(Ai, reverse=True)
Alice = 0
Bob = 0
for i in range(N):
  if i % 2 == 0:
    Alice += Ai[i]
  else:
    Bob += Ai[i]
print(Alice - Bob)