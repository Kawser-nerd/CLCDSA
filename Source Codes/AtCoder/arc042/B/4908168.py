x, y = map(int,input().split())
n = int(input())
info = [list(map(int,input().split())) for i in range(n)]
info.append(info[0])

def distance_from_p_to_l(p, l1, l2):
    length_l = ((l1[0]-l2[0])**2 + (l1[1]-l2[1])**2) ** (1/2)
    return ((l1[0]-p[0])*(l2[1]-p[1]) - (l1[1]-p[1])*(l2[0]-p[0])) / length_l 

p = (x, y)
ans = float("inf")
for i in range(n):
    a = info[i]
    b = info[i+1]
    ans = min(ans, distance_from_p_to_l(p, a, b))
print(ans)