n = int(input())
a = []
while n not in a:
    a.append(n)
    if n%2==0:
        n = n/2
    else:
        n = 3*n+1
print(len(a)+1)