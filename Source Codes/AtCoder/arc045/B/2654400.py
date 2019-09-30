n, m = map(int,input().split())

room = [0]*(n+1)
students = []
for _ in range(m):
    s, t = map(int, input().split())
    room[s-1] += 1
    room[t] -= 1
    students.append((s,t))

s = room[0]
room[0] = 0 if s < 2 else 1
for i in range(1,1+n):
    s += room[i]
    room[i] = 0 if s < 2 else 1 + room[i-1]

ans = []
for i, student in enumerate(students):
    s, t = student
    if room[t-1]-room[s-2] == t-s+1:
        ans.append(i+1)

print(len(ans))
for a in ans:
    print(a)