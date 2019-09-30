import math
n=int(input())
se=[input().split('-') for _ in range(n)]
time=[0]*((24+1)*12+1)
for sei in se:
    start=int(sei[0][0:2])*12+int(sei[0][2:4])//5
    end=int(sei[1][0:2])*12+math.ceil(int(sei[1][2:4])/5)
    for t in range(start, end):
        time[t]=1
is_rain=False
for i in range(len(time)):
    if time[i]==1 and not is_rain:
        is_rain=True
        start=i
    if time[i]==0 and is_rain:
        is_rain=False
        end=i
        h_start=str(start//12).zfill(2)
        m_start=str(start%12*5).zfill(2)
        h_end=str(end//12).zfill(2)
        m_end=str(end%12*5).zfill(2)
        print(h_start+m_start+ '-'+h_end+m_end)