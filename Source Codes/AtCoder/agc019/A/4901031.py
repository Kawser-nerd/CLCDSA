Q,H,S,D = map(int,input().split())
N = int(input())

efficient_num,efficient_cost = 0,8*Q
if(efficient_cost > 4*H): efficient_num,efficient_cost = 1,4*H
if(efficient_cost > 2*S): efficient_num,efficient_cost = 2,2*S
if(efficient_cost > D): efficient_num,efficient_cost = 3,D

#???0L or 1L???????????????
min_cost = 0

if(N%2 == 0):
 if(efficient_num == 0): min_cost = int(N/0.25)*Q
 elif(efficient_num == 1): min_cost = int(N/0.50)*H
 elif(efficient_num == 2): min_cost = N*S
 elif(efficient_num == 3): min_cost = (N//2)*D
 #??0L

else:
 N = 2*(N//2)
 if(efficient_num == 0): min_cost = int(N/0.25)*Q
 elif(efficient_num == 1): min_cost = int(N/0.50)*H
 elif(efficient_num == 2): min_cost = N*S
 elif(efficient_num == 3): min_cost = (N//2)*D
 #??1L
 #2L????????????1L???
 efficient_num,efficient_cost = 0,8*Q
 if(efficient_cost > 4*H): efficient_num,efficient_cost = 1,4*H
 if(efficient_cost > 2*S): efficient_num,efficient_cost = 2,2*S
  
 if(efficient_num == 0): min_cost += int(1/0.25)*Q
 elif(efficient_num == 1): min_cost += int(1/0.50)*H
 elif(efficient_num == 2): min_cost += 1*S
    
print(min_cost)