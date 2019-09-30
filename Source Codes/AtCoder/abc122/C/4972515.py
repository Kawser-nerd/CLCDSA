n, q = map(int, input().split())
s = input()

t = [0 for i in range(len(s))]
count = 0
for j in range(len(s)-1):
    if s[j] == "A" and s[j+1] == "C":
        count += 1
    t[j+1] = count

for k in range(q):
    l, r = map(int, input().split())
    print(t[r-1] - t[l-1])