N = int(input())
S = input().split()

S.sort()
count = 0
tmp = ''
for s in S:
    if tmp != s:
        count += 1
    tmp = s
if count == 3:
    print('Three')
else:
    print('Four')