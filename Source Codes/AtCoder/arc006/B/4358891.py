N, L = map(int, input().split())
l = []
for i in range(L):
    t = " "+input()+" "
    l.append(t)
l = l[::-1]
n = input()
s = n.index("o")
#print(s)
#print(l)
for i in l:
    #print(i,i[s+1-1],100)
    if i[s+1-1] == "-":
        s-=2
    elif i[s+1+1] == "-":
        s+=2
    #print(s)
print(s//2+1)