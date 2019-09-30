h, w, hh, ww = [int(i) for i in input().split()]
area = [h*w, hh*ww]
m = (h//hh) * (w // ww)
a_inv = (area[0] / m - area[1])
if(a_inv <= 0):
    print("No")
else:
    print("Yes")
    a = a_inv ** -1
    if(int(a) < a):
        a = int(a) + 1
    else:
        a = int(a)
    b = (area[1] - 1) * a + 1
    while(b >= (area[0]/m - 1)*a):
        a += 1
        b = (area[1] - 1) * a + 1
    a = str(a)
    b = str(-b)
    for i in range(h):
        ret = [None]*w
        for j in range(w):
            if((i+1) % hh == 0 and (j+1) % ww == 0):
                ret[j] = b
            else:
                ret[j] = a
        print(" ".join(ret))