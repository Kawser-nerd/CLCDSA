h,w = map(int,input().split())
num = []
for i in range(h):
    a = list(input())
    for j in range(w):
        if a[j] =='#':
            num.append(j+1)
            
for i in range(len(num)-1):
    if num[i] == num[i+1] or num[i]+1 == num[i+1]:
        continue
    else:
        print('Impossible')
        exit()
print('Possible')