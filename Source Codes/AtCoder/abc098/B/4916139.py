N = int(input())
S = str(input())
max = 0
list_S = list(S)
for i in range(N-1):
    X = list_S[:i]
    Y = list_S[-(len(list_S)-i):]
    result = set(X) & set(Y)
    if max < len(result):
        max = len(result)
print(max)