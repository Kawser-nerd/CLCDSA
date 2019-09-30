N, a = map(int, input().split())
K = int(input())
b_list = list(map(int, input().split()))
b_list.insert(0, 0)

visit = [a]
target = a

while True:
    if b_list[target] in visit:
        break
    else:
        target = b_list[target]
        visit.append(target)
last = b_list[target]
index = visit.index(last)
if len(visit) - index <= K:
    K -= index
    K %= len(visit) - index
    print(visit[K+index])
else:
    print(visit[K])