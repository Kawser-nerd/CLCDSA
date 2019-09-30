n = int(input())
ans = 0
li = []
for i in range(n):
    a,b = map(int,input().split())
    li.append((a,b))
li = li[::-1]
for (a,b) in li:
    ans += (b-((a+ans)%b))%b
print(ans)