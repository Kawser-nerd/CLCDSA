a,b = map(int,input().split())
grid = [["#" if i <50 else "." for i in range(100)] for j in range(100)]
#print(grid)

white_cnt = 1
while white_cnt < a:
  grid[(white_cnt//24)*2][(white_cnt%24)*2+1] = "."
  white_cnt +=1

black_cnt = 1
while black_cnt < b:
  grid[(black_cnt//24)*2][(black_cnt%24)*2+50+1] = "#"
  black_cnt += 1  

print(100,100)
for i in range(100):
  print("".join(grid[i]))