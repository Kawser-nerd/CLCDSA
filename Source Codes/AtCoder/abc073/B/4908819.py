N=int(input())
lr=[list(map(int, input().split())) for i in range(N)]
print(sum(list(zip(*lr))[1])-sum(list(zip(*lr))[0])+N)