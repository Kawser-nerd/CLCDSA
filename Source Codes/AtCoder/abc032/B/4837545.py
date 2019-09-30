s = input()
k = int(input())
 
dict = {}
 
for l in range(len(s)):
    for r in range(l+1,len(s)+1):
        if(r - l != k):
            continue
        dict[s[l:r]] = 1
 
ans = len(dict)
print(ans)