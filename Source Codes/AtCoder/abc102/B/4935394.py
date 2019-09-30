import itertools
N = int(input())
A = list(map(int, input().split()))
    
X = 0
for v in itertools.combinations(A, 2):
    if abs(v[0] - v[1]) > X:
        X = abs(v[0] - v[1])
        
print(X)