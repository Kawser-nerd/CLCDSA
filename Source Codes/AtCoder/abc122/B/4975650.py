S = list(input())
cnt = 0
tmp = 0
for x in S:
    if x == 'A' or x == 'T' or x == 'C' or x == 'G':
        tmp += 1
        #print('if')
    else:
        if tmp > cnt:
            cnt = tmp
        tmp = 0
        #print('else')
if tmp > cnt:
    cnt = tmp
print(cnt)