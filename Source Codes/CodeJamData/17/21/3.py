cases = int(input())
for cc in range(cases):
    distance, n = map(int, input().split())
    max_time = 0
    for i in range(n):
        position, speed = map(int, input().split())
        max_time = max(max_time, (distance - position) / speed)
    print('Case #%d: %.10lf' % (cc+1, distance / max_time))
