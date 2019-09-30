s=input()
k=int(input())
n=len(s)
koho=[]
for i in range(n):
    for j in range(k):
        if len(s[i:i+j+1])<=k:
            koho.append(s[i:i+j+1])

print(sorted(list(set(koho)))[k-1])