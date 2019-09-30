N = input()
L = list(map(int,input().split()))

def aoki(i,array):
    maxi = -100000000
    for j in range(len(array)):
        tmp = 0
        if j != i:
            if j < i:
                T = array[j:i+1]
            elif j > i :
                T = array[i:j+1]
            for k in range(len(T)):
                if k % 2 == 1:
                    tmp += T[k]
            if maxi < tmp:
                choice = j
                maxi = tmp
    return choice

maxi = -10000000000000
for i in range(len(L)):
    aoki_choice = aoki(i,L)
    tmp = 0
    if i < aoki_choice:
        T = L[i:aoki_choice+1]
        for j in range(len(T)):
            if j % 2 == 0:
                tmp += T[j]
    elif i > aoki_choice:
        T = L[aoki_choice:i+1]
        for j in range(len(T)):
            if j % 2 == 0:
                tmp += T[j]
  #  print(i,aoki_choice,tmp)
    maxi = max(tmp,maxi)

print(maxi)