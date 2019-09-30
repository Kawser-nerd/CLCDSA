R, G, B = map(lambda x:int(x), input().split(' '))

def sum_seq(a, l):
  return (a + l) * (abs(a-l)+1) / 2

def cost(left, _len):
  right = left + _len -1
  if left >= 0:
    return sum_seq(left, right)  
  elif right <= 0:
    return sum_seq(-right, -left)
  else:
    return sum_seq(0, -left) + sum_seq(0, right)

answer = float('inf')

for g_left in range(-500, 500):
  r_left = min(g_left - R, -100 - R // 2)
  b_left = max(g_left + G,  100 - B // 2)

  g_cost = cost(g_left, G) 
  r_cost = cost(r_left + 100, R) 
  b_cost = cost(b_left - 100, B)
  answer = min(answer, g_cost+r_cost+b_cost)
print(int(answer))