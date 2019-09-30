S = input()
ll = list(S.split('+'))
count = 0
for l in ll:
    if l.count('0') == 0:
        count += 1
print(count)