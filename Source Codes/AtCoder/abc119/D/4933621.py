import bisect


a, b, q = map(int, input().split())
s_list = [-100000000000000000]
t_list = [-100000000000000000]

for i in range(a):
    s = int(input())
    s_list.append(s)
for j in range(b):
    t = int(input())
    t_list.append(t)
s_list.append(100000000000000000)
t_list.append(100000000000000000)

for i in range(q):
    x = int(input())
    s_pos = bisect.bisect_left(s_list, x)
    t_pos = bisect.bisect_left(t_list, x)
    
    s_cand1 = x - s_list[s_pos-1]
    s_cand2 = s_list[s_pos] - x
    t_cand1 = x - t_list[t_pos-1]
    t_cand2 = t_list[t_pos] - x
    
    dist1 = max(s_cand1, t_cand1)
    dist2 = max(s_cand2, t_cand2)
    dist3 = min(s_cand1, t_cand2)*2 + max(s_cand1, t_cand2)
    dist4 = min(s_cand2, t_cand1)*2 + max(s_cand2, t_cand1)
    
    print(min(dist1, dist2, dist3, dist4))