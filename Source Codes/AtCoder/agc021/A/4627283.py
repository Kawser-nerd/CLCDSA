N = int(input())

ans = 0
bN = N
while bN:
    ans += bN % 10
    bN //= 10

for i in range(17, 0, -1):
    p = N // (10**i)
    if p == 0:
        continue
    
    # tmp = (p-1)*10**i  + int("9"*i)    # 51231 i == 4 で10000 となり、商は5
    tmp = 0
    rem = p-1
    while rem:
        tmp += rem % 10
        rem //= 10

    tmp += 9*i
    # print("i: ", i, "tmp: ", tmp)
    if tmp > ans:
        ans = tmp
print(ans)