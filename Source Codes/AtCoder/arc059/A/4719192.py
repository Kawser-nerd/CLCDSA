N = int(input())
a = list(map(int,input().split()))
count = 10**10
for y in range(min(a),max(a)+1):
    y_count = 0
    for x in a:
        y_count += (x-y)**2
    count = min(count,y_count)
print(count)