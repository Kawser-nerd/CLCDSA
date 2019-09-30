s=input()
k=int(input())
p=[chr(ord("a")+i)for i in range(26)]
l=[]
for i in range(26):
    if p[i] in s:
        h=[j for j,x in enumerate(s) if x==p[i]]
        for t in range(len(h)):
            for d in range(5):
                if h[t]+d>len(s)-1:
                    break
                else:
                    l.append(s[h[t]:h[t]+d+1])
        else:
            l=list(set(l))
            if len(l)>=k:
                l.sort()
                print(l[k-1])
                break