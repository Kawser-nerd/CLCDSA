a,b,c = map(int,input().split())
num = []
num.append(a)
num.append(b)
num.append(c)
ookii = num.copy()
ooi = max(ookii)
num.remove(max(num))
print(ooi * 10 + num[0] + num[1])