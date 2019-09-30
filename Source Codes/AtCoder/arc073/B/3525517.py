N,W=list(map(int,input().split()))

w1 = []
w2 = []
w3 = []
w4 = []


for i in range(N):
    w,v = list(map(int,input().split()))
    if i==0:
        w0 = w
    
    if w==w0:
        w1.append(v)
    elif w==w0+1:
        w2.append(v)
    elif w==w0+2:
        w3.append(v)
    else:
        w4.append(v)

w1.sort()
w1=w1[::-1]

w2.sort()
w2=w2[::-1]

w3.sort()
w3=w3[::-1]

w4.sort()
w4=w4[::-1]
max_V = 0
for i1 in range(len(w1)+1):
    for i2 in range(len(w2)+1):
        for i3 in range(len(w3)+1):
            for i4 in range(len(w4)+1):
                w = i1*w0 + i2*(w0+1) + i3*(w0+2) + i4 * (w0+3)
                if w<=W:
                    V = sum(w1[:i1])+sum(w2[:i2])+sum(w3[:i3])+sum(w4[:i4])
                    max_V = max(V,max_V)

print(max_V)