N = int(input())
imos = [0 for i in range(1443)]
 
def mystart(a_minute):
    while(1):
        if a_minute % 5 == 0 : break
        a_minute -=1
    return a_minute
 
def myend(a_minute):
    while(1):
        if a_minute % 5 == 0 : break
        a_minute += 1
    return a_minute
 
def output_time(a_minute):
    h = a_minute // 60
    h =  '%02d'% h
    m = a_minute % 60
    m = '%02d'% m
    return h+m 

nums = []

for i in range(N):
    time = [t for t in input().split("-")]
    time = [int(t[:2])*60 + int(t[2:]) for t in time]
    time = [mystart(time[0]),myend(time[1])]
    nums.append(time)
    
for n in nums:
    imos[n[0]] += 1
    imos[n[1]+1] -= 1

ans = []
j = 0
for i in imos:
    ans.append(j+i)
    j += i
    
start,end,flag = 0,0,False
 
for i in range(len(ans)):
    if ans[i] == 0 and flag == False : continue
    elif ans[i] == 0  and flag == True:
        end = i
        print(output_time(start) + "-" + output_time(end-1))
        start,end,flag = 0,0,False
    elif ans[i] != 0 and flag == False :
        start = i
        flag = True
    else:
        continue