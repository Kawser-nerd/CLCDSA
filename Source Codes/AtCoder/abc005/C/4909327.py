t = int(input())
n = int(input())
a_list = sorted(list(map(int, input().split())))
m = int(input())
b_list = sorted(list(map(int, input().split())))
if n < m:
    print('no')
else:
    count = 0
    for b in b_list:
        for a in range(len(a_list)):
            if b-a_list[a] <= t and b-a_list[a] >= 0:
                count += 1
                a_list.pop(a)
                break
    if count == len(b_list):
        print('yes')
    else:
        print('no')