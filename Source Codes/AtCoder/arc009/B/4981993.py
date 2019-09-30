B = input().split()
N = int(input())
A = [int(input()) for i in range(N)]

def value(n):
    s = str(n)
    a = [None]*len(s)
    for i,c in enumerate(s):
        k = B.index(c)
        a[i] = str(k)
    return int(''.join(a))

for a in sorted(A,key=lambda x:value(x)):
    print(a)