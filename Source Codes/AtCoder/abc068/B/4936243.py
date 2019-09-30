N = int(input())
flag = True
ans = 1
while flag:
    ans = ans * 2
    if ans > N:
        flag = False
print(ans//2)