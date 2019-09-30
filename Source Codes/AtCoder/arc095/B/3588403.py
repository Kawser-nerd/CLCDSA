N = int(input())
a = [int(i) for i in input().split()]

ai = max(a)
a.remove(ai) 
ans = 0
for aj in a:
    if min(ans,ai-ans) < min(aj,ai-aj):
        ans = aj
print(ai,ans)