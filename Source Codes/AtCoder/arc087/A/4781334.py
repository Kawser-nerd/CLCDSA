N = int(input())
A = [int(i) for i in input().split()]

dic = {}
for a in A:
    dic[a] = dic.get(a,0)+1
    
ans = 0
for k in dic:
    if dic[k]>k:
        ans += dic[k]-k
    elif dic[k]<k:
        ans += dic[k]
print(ans)