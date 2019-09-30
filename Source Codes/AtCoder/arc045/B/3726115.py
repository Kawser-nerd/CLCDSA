N, M = map(int, input().split())

classroom = [0] * (N+1+1)
start = [None] * M
end = [None] * M
for i in range(M):
    s, t = map(int, input().split())
    start[i] = s
    end[i] = t
    classroom[s] += 1
    classroom[t+1] -= 1
for i in range(1, N):
    classroom[i+1] += classroom[i]
classcover = [x if x == 1 else 0 for x in classroom]
i = 0 
j = 1
while i <= N:
    if classcover[i] == 1:
        j += 1
    classroom[i] = j
    i += 1

souji_count = 0
souji_list = []

for i, (s, e) in enumerate(zip(start, end)):
    if classroom[e] - classroom[s-1] == 0:
        souji_count += 1
        souji_list.append(i+1)
print(souji_count)
if souji_count > 0:
    for souji_num in souji_list:
        print(souji_num)