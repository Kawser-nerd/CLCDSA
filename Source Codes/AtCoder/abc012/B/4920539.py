s = int(input())
h = s // 3600
m = (s - h*3600) // 60
se = (s - h*3600 - m*60)
print("%02d:%02d:%02d" % (h, m, se))