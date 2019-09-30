N, M = map(int, input().split())
R = [[int(x)-1 for x in input().split()] for _ in range(M)]
# 0, 1, 2, ..., N-1

def maxBy(f, x, y):
    if f(x) < f(y):
        return f(y)
    else:
        return f(x)
    
def search(list1): # list1: choosed
    if len(list1) == N:
        return sum(list1)
    else:
        Flag = 0
        for i in range(len(list1)):
            if list1[i] == 1 and ([i, len(list1)] not in R):
                Flag = 1
                break
        if Flag == 0:
            return max(search(list1+[0]),
                       search(list1+[1]))
        else:
            return search(list1+[0])
        
result = search([])
print(result)