N = int(input())
flag = True

if N == 1:
    flag = False
elif N == 2:
    flag = True
elif N % 2 == 0:
    flag = False
else:
    for i in range(3, int(N**0.5)+1, 2):
        if N % i == 0:
            flag = False
            break

    if not(flag) and N % 5 != 0 and N % 3 != 0:
        flag = True

print("Prime" if flag else "Not Prime")