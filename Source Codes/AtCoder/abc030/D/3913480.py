N, a = map(int, input().split())
k = int(input())
bs = [a] + list(map(int, input().split()))
step = []
used = set()
cur = 0
while True:
    cur = bs[cur]
    if cur in used:
        T = step.index(cur)
        cycle = len(step)-T
        break
    used.add(cur)
    step.append(cur)
# print(step)
# print("T", T)
# print("cycle", cycle)

if k < len(step):
    print(step[k])

else :
    print(step[T + (k-T)%cycle])