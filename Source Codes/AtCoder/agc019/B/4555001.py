A = input()

ans = len(A)*(len(A)-1)//2 + 1

for i in range(ord("a"),ord("z")+1) :
    s = chr(i)
    c = A.count(s)
    ans -= c*(c-1)//2

print(ans)