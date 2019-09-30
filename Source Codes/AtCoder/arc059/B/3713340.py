a = input()
count = 0
if len(a) > 3:
    for i in range(len(a)-2):
        if a[i] == a[i+1] or a[i] == a[i+2] or a[i+1] == a[i+2]:
            print(i+1,i+3)
            count += 1
            break
else:
    if a[0] == a[1]:
        print(1,2)
        count += 1
if count == 0:
    print(-1,-1)