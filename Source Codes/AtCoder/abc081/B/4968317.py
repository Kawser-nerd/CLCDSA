N = input()
lst = list(map(int,input().split()))

counter = 0
while all([x%2 == 0 for x in lst]):
  counter += 1
  for k in range(int(N)):
    a = lst[k] / 2
    lst[k] = a
    
    

print(counter)