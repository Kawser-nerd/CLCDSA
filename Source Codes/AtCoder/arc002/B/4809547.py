Y,M,D = map(int,input().split('/'))

def is_uruu(y):
    if y%400 == 0:
        return True
    elif y%100 == 0:
        return False
    elif y%4 == 0:
        return True
    else:
        return False

lims = [0,31,28,31,30,31,30,31,31,30,31,30,31]

while M < 13:
    lim = lims[M]
    if is_uruu(Y) and M==2: lim += 1
    while D <= lim:
        if Y%(M*D)==0:
            print("{0:02d}/{1:02d}/{2:02d}".format(Y,M,D))
            exit()
        D += 1
    D = 1
    M += 1
print("{0:02d}/{1:02d}/{2:02d}".format(Y+1,1,1))