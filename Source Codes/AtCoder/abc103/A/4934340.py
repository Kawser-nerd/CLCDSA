task = list(map(int, input().split()))
task = sorted(task)
cost = 0
for i in range(2):
  cost += task[i+1] - task[i]
print(cost)