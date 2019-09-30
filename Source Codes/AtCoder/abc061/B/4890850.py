N, M = map(int, input().split())
numbers = [map(int, input().split()) for _ in range(M)]
numbers = [flatten for inner in numbers for flatten in inner]

for i in range(1,N+1):
  print(numbers.count(i))