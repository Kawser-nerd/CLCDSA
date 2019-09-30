def tobi(string):
    return format(int(string),"07b")
n,k = map(int,input().split())
T = [list(map(tobi,input().split())) for _ in range(n)]
flag = True

def bi5(inte,a,b):#a**b???????
    ans = [0]*b
    for i in range(b-1,-1,-1):
        if inte >= a**i:
            ans[i] = int(inte/(a**i))
            inte = inte % a**i
    return ans
for i in range(k**n):
    temp = [0]*7
    for p,l in zip(bi5(i,k,n),range(n)):
        for t,m in zip(T[l][p],range(7)):
            temp[m] += int(t)
    for j in range(7):
        temp[j] = temp[j]%2
    if sum(temp) == 0:
        print("Found")
        flag = False
        break
if flag:
    print("Nothing")