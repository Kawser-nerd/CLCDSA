import math

num=int(input())
arr = list(map(int, input().split())) #i_1 i_2?????i??????

# ???????
arr_new = sorted(arr, reverse=True)
ans = 0
index = 0
for i in range(math.ceil(num/2)):
    ans += arr_new[index]
    index += 2

print(ans)