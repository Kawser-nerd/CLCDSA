h,w=map(int,input().split())
s=[input() for i in range(h)]
print("#"*(w+2))
for i in range(h):
    print("#"+s[i]+"#")
print("#"*(w+2))