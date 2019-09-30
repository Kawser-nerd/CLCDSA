# coding: utf-8

N = int(input())
timetable = [[] for i in range(N)]
for i in range(N):
    start, end = input().rstrip().split('-')
    start = int(start)
    if start%10<5:
        start -= start%10
    else:
        start -= start%10-5
    end = int(end)
    if 0<end%10<=5:
        end += 5-end%10
    elif 5<end%10:
        end += 10-end%10
        if end%100 == 60:
            end += 40
    timetable[i] = [start,end]

timetable.sort()
i = 0
while i < len(timetable)-1:
    if timetable[i][1]-timetable[i+1][0] >= 0:
        if timetable[i][1] < timetable[i+1][1]:
            timetable[i][1] = timetable[i+1][1]
        del timetable[i+1]
        i -= 1
    i += 1

for time in timetable:
    print(str(time[0]).zfill(4)+'-'+str(time[1]).zfill(4))