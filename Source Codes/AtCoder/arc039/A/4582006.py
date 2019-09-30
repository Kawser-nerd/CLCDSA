a, b = input().split()
res1 = 900 + int(a[1:]) -int(b)
res2 = int(a[0])*100 + 90 + int(a[2]) - int(b)
res3 = int(a[:2])*10 + 9 - int(b)
res4 = int(a) - int(b[1:]) - 100
res5 = int(a) - int(b[0])*100 - int(b[2])
res6 = int(a) - int(b[:2])*10
print(max(res1,res2,res3,res4,res5,res6))