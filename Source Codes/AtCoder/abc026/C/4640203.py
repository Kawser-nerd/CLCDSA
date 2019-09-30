from collections import defaultdict as dd
n = int(input())
salary = [0]*(n+1)
d = dd(list)
for i in range(2,n+1):
  d[int(input())].append(i)
def calcsalary(i):
  if d[i] == []:
    salary[i] = 1
    return 1
  else:
    subord = []
    for x in d[i]:
      if salary[x]:
        subord.append(salary[x])
      else:
        subord.append(calcsalary(x))
    salary[x] = max(subord) + min(subord) + 1
    return salary[x]
print(calcsalary(1))