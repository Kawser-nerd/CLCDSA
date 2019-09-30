D,J = input().split(" "),input().split(" ")
D,J = [int(i) for i in D],[int(i) for i in J]
ans = 0
for i in range(7):
    ans += max(D[i],J[i])
print(ans)