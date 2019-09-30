N = int(input())
a = list(map(int,input().split()))
out = 0
for n in a:
    while n > 1:
        if n%2==0:
            n//=2
            out +=1
        else:
            n=0
print(out)