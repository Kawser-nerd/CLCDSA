n, a = map(int, input().split())
k = int(input())
b = list(map(int, input().split()))

history = []
while not a in history:
    history.append(a)
    a = b[a - 1]

p = history.index(a)
if k < p:
    print(history[k])
else:
    q = len(history) - p
    print(history[(k - p) % q + p])