n,l = [int(i) for i in input().split()]
a=[int(i) for i in input().split()]
#b=[int(i) for i in input().split()]

max_len   = a[0]+a[1]
max_joint = 1

for i in range(1,n-1):
    len = a[i] + a[i+1]
    if len > max_len:
        max_len   = len
        max_joint = i+1


if max_len < l:
    print("Impossible")
    exit()
else:
    print("Possible")
    for i in range(1,max_joint):
        print(i)
    for i in range(n-1, max_joint, -1):
        print(i)
    print(max_joint)