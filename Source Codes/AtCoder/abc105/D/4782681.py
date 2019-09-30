N,M = map(int,input().split())

li = list(map(int,input().split()))
b_li = [0]
accum_value = 0
for i in range(N):
    accum_value += li[i]
    b_li.append(accum_value)

mod_dict = dict()
# print(b_li)
for i in range(N+1):
    mod = b_li[i] % M
    if mod not in mod_dict.keys():
        mod_dict[mod] = 1
    else:
        mod_dict[mod] += 1
# print(mod_dict)

ans = 0
for i in mod_dict.keys():
    val = mod_dict[i]
    ans += val*(val-1)/2

print(int(ans))