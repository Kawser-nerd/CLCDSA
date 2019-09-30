n = int(input())

arr = []

for i in range(n):
    a, b = map(int, input().split())
    arr.append([i, a, b])
    
    
left_arr = sorted(arr, key=lambda x: x[2])
right_arr = sorted(arr, key=lambda x: x[1], reverse=True)

ans = 0

f = 0
ok = [0 for i in range(n)]

#if abs(left_arr[0][2]) < abs(right_arr[0][1]):
#    f = 1
    
lp = 0
rp = 0
now = 0
for i in range(n):
    if f == 0:
        while True:
            if ok[left_arr[lp][0]] == 0:
                break
            else:
                lp += 1
        if now >= left_arr[lp][1] and now <= left_arr[lp][2]:
            ans += 0
        elif abs(left_arr[lp][1] - now) < abs(left_arr[lp][2] - now):
            ans += abs(left_arr[lp][1] - now)
            now = left_arr[lp][1]
        else:
            ans += abs(left_arr[lp][2] - now)
            now = left_arr[lp][2]
        ok[left_arr[lp][0]] = 1
        lp += 1
        f = 1
    else:
        while True:
            if ok[right_arr[rp][0]] == 0:
                break
            else:
                rp += 1
        if now >= right_arr[rp][1] and now <= right_arr[rp][2]:
            ans += 0
        elif abs(right_arr[rp][1] - now) < abs(right_arr[rp][2] - now):
            ans += abs(right_arr[rp][1] - now)
            now = right_arr[rp][1]
        else:
            ans += abs(right_arr[rp][2] - now)
            now = right_arr[rp][2]
        ok[right_arr[rp][0]] = 1
        rp += 1
        f = 0
        
ans += abs(now)

temp = ans

ans = 0

f = 1
for i in range(n):
    ok[i] = 0

lp = 0
rp = 0
now = 0
for i in range(n):
    if f == 0:
        while True:
            if ok[left_arr[lp][0]] == 0:
                break
            else:
                lp += 1
        if now >= left_arr[lp][1] and now <= left_arr[lp][2]:
            ans += 0
        elif abs(left_arr[lp][1] - now) < abs(left_arr[lp][2] - now):
            ans += abs(left_arr[lp][1] - now)
            now = left_arr[lp][1]
        else:
            ans += abs(left_arr[lp][2] - now)
            now = left_arr[lp][2]
        ok[left_arr[lp][0]] = 1
        lp += 1
        f = 1
    else:
        while True:
            if ok[right_arr[rp][0]] == 0:
                break
            else:
                rp += 1
        if now >= right_arr[rp][1] and now <= right_arr[rp][2]:
            ans += 0
        elif abs(right_arr[rp][1] - now) < abs(right_arr[rp][2] - now):
            ans += abs(right_arr[rp][1] - now)
            now = right_arr[rp][1]
        else:
            ans += abs(right_arr[rp][2] - now)
            now = right_arr[rp][2]
        ok[right_arr[rp][0]] = 1
        rp += 1
        f = 0
        
        
ans += abs(now)

if temp>ans:
    ans = temp
print(ans)