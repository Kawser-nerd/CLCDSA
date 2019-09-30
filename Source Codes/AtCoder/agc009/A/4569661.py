n = int(input())
ans = 0
li = []
for i in range(n):
    a,b = map(int,input().split())
    li.append((a,b))
for (a,b) in li[::-1]:
    ans += (b-((a+ans)%b))%b
print(ans)