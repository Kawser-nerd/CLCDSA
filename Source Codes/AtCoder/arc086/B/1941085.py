N = int(input())
a = [int(n) for n in input().split()]

steps = []

a_argmax, a_max = max(enumerate(a), key = lambda x:x[1])
a_argmin, a_min = min(enumerate(a), key = lambda x:x[1])



if a_max + a_min >= 0:
    for i in range(N):
        steps.append((a_argmax, i))
    for i in range(N-1):
        steps.append((i, i+1))
else:
    for i in range(N):
        steps.append((a_argmin, i))
    for i in range(N-1, 0, -1):
        steps.append((i, i-1))

print(2*N-1)
for x, y in steps:
    print("{} {}".format(x+1, y+1))