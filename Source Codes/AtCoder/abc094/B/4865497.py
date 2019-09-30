N,M,X = map(int,input().strip().split())

As = list(map(int,input().strip().split()))

left = list(filter(lambda x: x < X,As))
right = list(filter(lambda x: x > X,As))

print(min(len(left),len(right)))