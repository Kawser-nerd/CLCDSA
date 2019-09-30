N = int(input())
x = []
for i in range(N):
    x.append(list(input()))
x.append("..........")
def dele(i,k,x):
    if x[i][k] == "o":
        x[i][k] = "."
        dele(i+1,k,x)
    else:
        return True
ans = 0

for i in range(N):
    for k in range(9):
        if x[i][k] == "x":
            ans += 1
        elif x[i][k] == "o":
            dele(i+1,k,x)
            ans += 1
print(ans)