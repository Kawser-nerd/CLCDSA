L = list(input().split('+'))
ans = []
cnt = 0
for x in L:
    if '0' in x:
        pass
    else:
        cnt += 1
print(cnt)