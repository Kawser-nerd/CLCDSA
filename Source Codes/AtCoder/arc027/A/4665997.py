h,m = map(int,input().split())
res = 0
if m > 0:res = 60-m + (17-h) * 60
else:res = (18-h) * 60
print(res)