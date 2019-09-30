N, D, K = map(int, input().split())

l_list = []
r_list = []
for i in range(D):
    l, r = map(int, input().split())
    l_list.append(l)
    r_list.append(r)   
    
ans = [0]*K

for i in range(K):
    s, t = map(int, input().split())
    
    if s < t:
        for j in range(D):
            if l_list[j] <= s <= r_list[j]:
                s = r_list[j]
                if s >= t:
                    ans[i] = j+1
                    break
    else:
        for j in range(D):
            if l_list[j] <= s <= r_list[j]:
                s = l_list[j]
                if s <= t:
                    ans[i] = j+1
                    break

for i in range(K):
    print(ans[i])