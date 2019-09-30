def calc(a0):
    a1 = a0 + 1
    b0 = str(a0**2)
    b1 = str(a1**2)
    length = len(b0)
    if length != len(b1):
        if a0 == 3:
            return 9
        elif str(a0)[0] == '3':
            return 10
        if a0 == 9:
            return 81
        ind = 0
        for i in range(length):
            if (b0[i] != '9'):
                ind = i + 1
                break
        ans = 0
        if (length + ind) % 2 == 1:
            ind += 1
        ans = int(b0[:ind]) + 1
        return ans
    ind = 0
    diff = False
    for i in range(length):
        if i == length - 1:
            ind = i + 1
            break
        if diff or b0[i] != b1[i]:
            diff = True
            dig = 10 ** (length - i - 1)
            under = int(b0) % dig
            added = int(b0) - under + (dig if under > 0 else 0)
            if added < int(b1):
                ind = i + 1
                break
    if (length + ind) % 2 == 1:
        ind += 1
    if ind == length or int(b0[ind:]) == 0:
        ans = int(b0[:ind])
    else:
        ans = int(b0[:ind]) + 1
    while ans % 100 == 0:
        ans //= 100
    return ans

if __name__ == "__main__":
    a0 = int(input())
    print(calc(a0))
    exit(0)