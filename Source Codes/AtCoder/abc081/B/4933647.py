N = int(input())
a = list(map(int, input().split()))
counter = 0
roop_flag = True
while roop_flag:
    for i in range(N):
        if a[i] % 2 != 0:
            roop_flag = False
            break
        else:
            a[i] = a[i]/2
    else:
        counter += 1

print(counter)