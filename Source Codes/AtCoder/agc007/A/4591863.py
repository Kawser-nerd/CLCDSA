h,w = map(int,input().split())
A = [input() for i in range(h)]

count = 0

for a in A:
    count += a.count('#')

if count == h+w-1:
    print("Possible")
else:
    print("Impossible")