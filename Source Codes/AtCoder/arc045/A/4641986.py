N = list(map(str,input().split()))
K = []
for i in range(len(N)):
    if N[i] == "Left":
        K.append("<")
    elif N[i] == "Right":
        K.append(">")
    else:
        K.append("A")
print(*K)