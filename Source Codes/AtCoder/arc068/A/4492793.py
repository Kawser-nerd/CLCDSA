x = int(input())
count = 0
q, mod = divmod(x, 11)
count += q*2
if mod > 0:
    if(mod <= 6):
        count += 1
    else:
        count += 2
print(count)