import queue

A = []
for i in range(10):
    A.append(input())

Done = [[0 for i in range(10)] for j in range(10)]
q = queue.Queue()

def check():
    while not q.empty():
        now = q.get()
        i = int(now[0])
        j = int(now[1])
        Done[i][j] = 1
        if i-1 >= 0:
            if Done[i-1][j] == 0 and A[i-1][j] is 'o':
                q.put([i-1,j])
        if j-1 >= 0:
            if Done[i][j-1] == 0 and A[i][j-1] is 'o':
                q.put([i,j-1])
        if i+1 < 10:
            if Done[i+1][j] == 0 and A[i+1][j] is 'o':
                q.put([i+1,j])
        if j+1 < 10:
            if Done[i][j+1] == 0 and A[i][j+1] is 'o':
                q.put([i,j+1])

def check_all():
    for i in range(10):
        for j in range(10):
            if A[i][j] is 'o' and Done[i][j] == 0:
                return 'NO'
    return 'YES'

flag = 'NO'
for i in range(10):
    for j in range(10):
        if A[i][j] == 'x':
            q.put([i,j])
            check()
            if check_all() is 'YES':
                flag = 'YES'
        Done = [[0 for i in range(10)] for j in range(10)]

print(flag)