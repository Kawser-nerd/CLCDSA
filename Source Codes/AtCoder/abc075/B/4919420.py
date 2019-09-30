h,w=map(int,input().split())
s=[input() for _ in range(h)]
for i in range(h):
    l=""
    for j in range(w):
        if s[i][j]=="#":
            l+="#"
        else:
            l+=str(sum([t[max(0,j-1):min(w,j+2)].count("#") for t in s[max(0,i-1):min(h,i+2)]]))
    print(l)