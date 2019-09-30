#input
n = int(input())
blue = []
for i in range(n):
    s = input()
    blue.append(s)
m = int(input())
red = []
for i in range(m):
    t = input()
    red.append(t)
#maniplate
ans = [0]
for word in (blue + red):
    count = sum([s == word for s in blue])
    count -= sum([t == word for t in red])
    ans.append(count)
#output
print(max(ans))