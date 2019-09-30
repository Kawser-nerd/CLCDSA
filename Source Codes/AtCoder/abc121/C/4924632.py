N,M = map(int,input().split())
drink_dict = {}
for i in range(N):
  A,B = map(int,input().split())
  if A not in drink_dict:
  	drink_dict[A] = B
  else:
    drink_dict[A] += B 
drink_list = sorted(drink_dict.items())
total_number = 0
total_price = 0
for i in drink_list:
  if total_number + i[1] >= M:
    print(total_price + (M-total_number) * i[0])
    break;
  else:
    total_price+=i[0]*i[1]
    total_number+= i[1]