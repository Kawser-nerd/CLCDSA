N = int(input())
nums=[i*10000/N for i in range(1,N+1)]
print(int(sum(nums)))