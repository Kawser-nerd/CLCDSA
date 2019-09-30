A,B = map(int, input().split())
 
def F0(n):
    if n%4 == 1:
        return 1
    if n%4 == 2:
        return n + 1
    if n%4 == 3:
        return 0
    if n%4 == 0:
        return n
    if n == 0:
        return 0
 
 
print(F0(A-1)^F0(B))