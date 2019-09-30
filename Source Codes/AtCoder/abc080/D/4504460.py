import pprint

N, C = map(int, input().split())
stc = []

max_time = 0
for _ in range(N):
    tmp = list(map(int,input().split()))
    max_time = max(max_time,tmp[1])
    stc.append(tmp)

stc.sort(key=lambda x: (x[0]))
# pprint.pprint(stc,width=20)
# print(max_time)

ongoings = []

ans = 0

for prog in stc:
    # print("prog:",prog)
    flag = False
    for og in ongoings:
        if og[2] == prog[2]:
            og[1] = prog[1]
            flag = True
            break
        elif og[1] < prog[0]:
            og[1] = prog[1]
            og[2] = prog[2]
            flag = True
            break
    if not flag:
        ongoings.append(prog)
    # print("ogs:",ongoings)
    ans = max(ans,len(ongoings))

print(ans)