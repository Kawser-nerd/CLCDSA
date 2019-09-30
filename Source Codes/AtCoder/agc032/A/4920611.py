n = int(input())
b = list(map(int, input().split()))

ans = []
while True:
    num = 0
    for i in range(len(b)):
        if b[i] == i + 1:
            num = i + 1
    else:
        if num == 0:
            print("-1")
            quit()
        else:
            ans.append(b[num - 1])
            del b[num - 1]
    if b == []:
        break


for i in ans[::-1]:
    print(i)