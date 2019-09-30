N = int(input())
a = list(map(int,input().split()))
g = 4000001
for i in range(min(a),max(a)+1):
    temp_g = 0
    for d in a:
        temp_g += (i-d)**2
    g = min(g,temp_g)
print(g)