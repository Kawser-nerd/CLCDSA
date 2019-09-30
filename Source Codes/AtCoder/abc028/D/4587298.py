a , b = map(float, input().split())
s = 0
s+= 1
s+=(a-1)*3
s+=6*((b-1)*(a-b))

s/=a**3
print(s)