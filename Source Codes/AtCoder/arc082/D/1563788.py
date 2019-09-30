import bisect
oX = int(input())
K = int(input())
r= list(map(int,input().split()))

# a X-a
# min(max(0,a-r[0]))
#  a-r[0]+r[1]

def calc_time(t):
    val = bisect.bisect_left(t,r)
    diff= t- r[val]
    return val,diff


# [sep1,sep2,a<sep1,sep1<a<sep2,a>sep2  ]

last =(0,oX,0 ,0,oX)
res =[last]
for i,tr in enumerate(r):
    sep1,sep2,X,Y,Z=last
    dt = tr if i==0 else tr-r[i-1]
    if i%2==0: # a ->b

        X = max(0,X-dt)
        Y = Y-dt
        Z = max(0,Z-dt)
        sep1 = max(sep1,-Y)
    else: #b-> a
        X = min(oX,X+dt)
        Y= Y+dt

        Z = min(oX,Z+dt)
        sep2 = min(sep2,oX-Y)

    last = (sep1,sep2,X,Y,Z)
    res.append(last)

#print(res)


Q = int(input())

r_index=0
r.insert(0,0)
r.append(10000000000)
for i in range(Q):
    def calc(X,r_index,diff):
        tmp = 1 if r_index%2 else -1
        return min(oX,max(0,X +tmp* diff))
    t,a =list(map(int,input().split()))
    while r[r_index]< t:
        if r[r_index+1] >t:
            break
        r_index+=1
    sep1, sep2, X, Y, Z = res[r_index]
    diff = t -r[r_index]
    #print(t,diff,r_index,r[r_index])
    if a< sep1:
        print(calc(X,r_index,diff))
    elif a>sep2:
        print(calc(Z,r_index,diff))
    else:
        print(calc(a+Y,r_index,diff))