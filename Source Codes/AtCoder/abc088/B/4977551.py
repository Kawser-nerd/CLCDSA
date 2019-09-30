N = int(input())
Ai = input().split()
Ai = [int(n) for n in Ai]
Ai = sorted(Ai, reverse=True)
Alice = 0
Bob = 0
i = 0
while True:
  if i+1 <= N-1:
    Alice += Ai[i]
    Bob += Ai[i+1]
  if i == N-1:
    Alice += Ai[i]
  if i > N-1:
    break
  i = i + 2

print(Alice - Bob)