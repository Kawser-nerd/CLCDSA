S = input()
L = list(map(int, input().split()))

T = ''
if L[0] == 0:
    T += '\"'
for i, s in enumerate(S):
    if i + 1 in L:
        T += s + '\"'
    else:
        T += s
        
print(T)