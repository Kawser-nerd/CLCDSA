N = int(input())
W = input().split()
W[-1] = W[-1][:-1]
num = 0
for i in W:
    if i in ["TAKAHASHIKUN", "Takahashikun", "takahashikun"]:
        num += 1

print(num)