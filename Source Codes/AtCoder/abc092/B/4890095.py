N = int(input())
D,X = map(int,input().split())
lists = []
day_list = []
chocolate = 0
for i in range(N):
        A = int(input())
        lists.append(A)
        day_list = []
        for j in range(D):
                if j*lists[i]+1 <= D:
                        day_list.append(j*lists[i]+1) 
                
        chocolate += len(day_list)
print(X+chocolate)