n = int(input())
L = [int(input())]
l = 1

# ???????????????
for _ in range(n-1):
    w = int(input())
    if w > L[-1]:
        L.append(w)
        l += 1
    else:
        for i in range(l):
            if w <= L[i]:
                L[i] = w
                break

print(l)