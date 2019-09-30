N, K = map(int, input().split())
R = [int(x) for x in input().split()]

def sort(list1):
    return sorting(list1)
    
def sorting(list1):
    if len(list1) == 1:
        return list1
    mid = len(list1) // 2
    return merge(sorting(list1[:mid]), sorting(list1[mid:]))

def merge(list1, list2):
    result = []
    i = 0
    j = 0
    m = len(list1)
    n = len(list2)
    while(i+j<m+n):
        if j == n or (i < m and list1[i] < list2[j]):
            result += [list1[i]]
            i += 1
        else:
            result += [list2[j]]
            j += 1
            
    return result

R = sort(R)
R[:N-K] = []
C = 0
for x in R:
    if C < x:
        C = (C+x)/2
        
print(C)