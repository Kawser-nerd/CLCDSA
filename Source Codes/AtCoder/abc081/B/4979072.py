n=int(input())
data=list(map(int, input().split()))
for i in range( max(data)):
  even_data = list(filter(lambda x: x%2==0, data))
  if len(even_data) < n:
    print(i)
    break
  data = list(map( lambda x: x / 2,  data))