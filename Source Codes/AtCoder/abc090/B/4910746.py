A, B= map(int, input().split())

count=0
for tmp in range(A, B+1):
    num=[]
    while tmp > 0:
        num.append(tmp % 10)
        tmp = tmp // 10
    
    if num[0]==num[4] and num[1]==num[3]:
        count+=1

print(count)