N = int(input())
if N == 1:
    print('Hello World')
    exit()
else:
    l = []
    for i in range(N):
        l.append(int(input()))
print(sum(l))