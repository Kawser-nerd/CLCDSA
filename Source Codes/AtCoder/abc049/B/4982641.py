h,w =map(int,input().split())
s=[]
for i in range(h):
    s.append(list(input().split()))
    s.append(s[-1])
for j in range(2*h):
    print("".join(s[j]))