S = input()
X = ['N' in S, 'S' in S, 'W' in S, 'E' in S]
print('Yes' if X[0]==X[1] and X[2]==X[3] else 'No')