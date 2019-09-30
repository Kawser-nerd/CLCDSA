n = int(input())
s = input()
lv = [0] * n

lvi = 0
for i,v in enumerate(s):
    if v == '(' :
        lvi += 1
    else:
        lvi -= 1
    lv[i] = lvi
l = min(0,min(lv))
r = -lv[-1] + l

print('('*(-l) + s + ')'*(-r))