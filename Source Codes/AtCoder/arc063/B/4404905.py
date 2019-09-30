n, t = map(int, input().split())
ax = list(map(int, input().split()))
# i???????????????????
sell = []
for a in ax[::-1][:n-1]:
    if len(sell) == 0:
        sell.append([a,1])
        continue
    if a > sell[-1][0]:
        sell.append([a,1])
    elif a == sell[-1][0]:
        sell.append([a, sell[-1][1]+1])
    else:
        sell.append(sell[-1])
sell = sell[::-1]
ans = {}
for i in range(n-1):
    sell_p, cnt = sell[i]
    ans[sell_p-ax[i]] = ans.get(sell_p-ax[i],0)+1
print(ans[max(ans.keys())])