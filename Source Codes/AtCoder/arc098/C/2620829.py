N,K,Q = map(int,input().split())
A = list(map(int,input().split()))
B = sorted(A) # A ????
L = [[i,B[i+Q-1] - B[i]] for i in range(N-Q+1)] # B??X-Y??????????
sL = sorted(L,key=lambda x:x[1]) # L????

if Q == 1:
    # ???????? -> max == min -> 0
    print(0)
    exit()

if Q == N - K + 1:
    # ?????????? = ??????????
    print(L[0][1])
    exit()

if K == 1:
    # ??????? -> ?????????????
    print(sL[0][1])
    exit()

if sL[0][0] == 0:
    # min????? ???????????
    print(sL[0][1])
    exit()

if sL[0][1] == sL[len(sL)-1][1]:
    print(sL[0][1])
    exit()

now_max_value = -1
now_min_value = -1
now_min_XY = int(1e10)

for key,value in sL:
    max_value = B[key + Q - 1]
    min_value = B[key]
    C = [(i if i >= min_value else None) for i in A]
    i = 0
    j = 0
    count = 0
    min_OK = max_OK = False
    while i < N:
        if not C[i]:
            i += 1
            continue
        j = i + 1
        while j < N:
            if not C[j]:
                break
            j += 1
        tmp = (j-i) - K + 1
        if  tmp < 1:
            # ?????????????
            #if min(C[i:j]) < max_value:
            #    count = 0
            #    break
            i = j + 1
            continue
        sC = sorted(C[i:j])
        if not min_OK and (sC[0] == min_value):
            min_OK = True
        if not max_OK and max_value in sC[0:tmp]:
            max_OK = True
        #if sC[tmp] < max_value:
        #    count = 0
        #    break
        count += tmp - len([i for i in sC[:tmp] if i > max_value])
        i = j +1
    if min_OK and max_OK and (count >= Q):
        print(value)
        exit()
    now_min_XY = min(now_min_XY,now_max_value - now_min_value)
    now_max_value = -1
    now_min_value = -1

print(L[0][1])