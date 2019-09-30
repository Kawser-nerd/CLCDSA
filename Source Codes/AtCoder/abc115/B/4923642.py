N=int(input())
list_n=[int(input()) for _ in range(N)]
print(sum(list_n)-max(list_n)//2)