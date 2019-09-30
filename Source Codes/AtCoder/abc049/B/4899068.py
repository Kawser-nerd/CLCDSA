h, w = map(int, input().split())
image = []
for i in range(h):
    image.append(input())
for row in image:
    print(row+"\n"+row)