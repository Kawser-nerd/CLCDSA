import math
N = int(input())
List = list(map(int, input().split()))
print(math.ceil(sum(List)/(N-List.count(0))))