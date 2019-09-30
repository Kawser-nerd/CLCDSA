def create_Row(S,E):
    list = []
    start = S
    while start <= E:
        list.append(start)
        start+=start
    return list

X,Y =map(int,input().split())
A = len(create_Row(X,Y))
print(A)