i = list(map(int,input().split()))
s = list(map(int,input().split()))
a = i[0]*i[1]+s[0]*s[1]-i[0]*s[1]-i[1]*s[0]
print(a)