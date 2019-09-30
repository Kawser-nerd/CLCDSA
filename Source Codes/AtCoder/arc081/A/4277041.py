N=int(input())
l=map(int,input().split())
h=dict()
m1=0
m2=0
for i in l:
        if(i not in h):
                h.update({i:1})
        else:
                del h[i]
                if(i>m1):
                        m2=m1
                        m1=i
                else:
                        m2=max(m2,i)
print(m1*m2)