s = [int(i) for i in input()]
k = int(input())

count = 0
while s[0] == 1:
    s = s[1:]
    count += 1
    if len(s) == 0:
        break
if k <= count:
    print(1)
else:
    print(s[0])