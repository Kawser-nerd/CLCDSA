A,B = map(int,input().split())
a = A
b = B
if a < 900 :
    a = 900 + A % 100
elif a % 100 < 90 :
    a = 990 + A % 10
else :
    a = 999

if b > 199 :
    b = 100 + B % 100
elif b % 100 > 9 :
    b = 100 + B % 10
else :
    b = 100

print(max(A-b, a-B))