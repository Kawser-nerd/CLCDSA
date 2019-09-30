k = int(input())
a = 0
data = list(map(int, input().split()))
data = sorted(data)
#print(data)
for num in range(len(data)-1):
    a += data[num]
#print("k is", k)
#print("a is", a)
if data[-1] < a:
    print('Yes')
else:
    print("No")