n,l = map(int,input().split())
info =[None]*l

for i in range(l):
  info[i] = input().split("|")
  
#info?0???9??????(?)???????...???
#???????????????????1??????n???????????????????????
goal = input()

for i in range(len(goal)):
  if goal[i]=="o":
    goal_n = i//2
    
for i in range(l-1,-1,-1):
  if info[i][goal_n]=="-":
    goal_n = goal_n - 1
  elif info[i][goal_n+1]=="-":
    goal_n = goal_n + 1

print(goal_n+1)