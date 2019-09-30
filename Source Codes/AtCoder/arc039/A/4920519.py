a,b = map(int,input().split())

str_a = str(a)
str_b = str(b)

li_a = [a, int("9"+str_a[1:]), int(str_a[0]+"9"+str_a[2]), int(str_a[:2]+"9")]
li_b = [b, int("1"+str_b[1:]), int(str_b[0]+"0"+str_b[2]), int(str_b[:2]+"0")]

ans = -999
for a_ in li_a:
    ans = max(ans, a_ - b)
for b_ in li_b:
    ans = max(ans, a - b_)

print(ans)