S = list(input().split())

T = []
for s in S:
    if s == 'Left':
        T.append('<')
    if s == 'Right':
        T.append('>')
    if s == 'AtCoder':
        T.append('A')
        
print(' '.join(T))