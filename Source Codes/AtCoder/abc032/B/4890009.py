s=input()
k=int(input())
c=[]
c_set=set(c)
for i in range(len(s)-1):
    if len(s[i:i+k]) == k:
        c_set.add(s[i:i+k])
print(len(c_set))