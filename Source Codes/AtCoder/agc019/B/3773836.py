ch = ['a','b','c','d','e','f','g','h','i','j','k','l','m',
    'n','o','p','q','r','s','t','u','v','w','x','y','z']

p = []

a = list(input())
n = len(a)
for i in range(len(ch)):
    p.append(a.count(ch[i]))

res = n*(n-1)//2

for i in range(len(ch)):
    res = res - p[i] * (p[i]-1) //2
print(res+1)