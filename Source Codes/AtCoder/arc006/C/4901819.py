N = int(input())
r = [0]
for i in range(N):
    tmp = int(input())
    if tmp > max(r):
        r.append(tmp)
    else:
        i = 0
        while r[i] < tmp:
            i += 1
        r[i] = tmp
    r.sort()
print(len(r)-1)