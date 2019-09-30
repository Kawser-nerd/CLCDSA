N = int(input())
red_points = [tuple(map(int, input().split())) for i in range(N)]
blue_points = [tuple(map(int, input().split())) for i in range(N)]

red_points.sort(key=lambda x: -x[1])
blue_points.sort(key=lambda x: x[0])

count = 0

points_used = [False for i in range(N)]

for blue in blue_points:
    for i, red in enumerate(red_points):
        if not points_used[i] and red[0] < blue[0] and red[1] < blue[1]:
            count += 1
            points_used[i] = True
            break
            
print(count)