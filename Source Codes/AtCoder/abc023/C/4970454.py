import collections

R, C, K = map(int, input().split())
N = int(input())

r_candies = [0]*R
c_candies = [0]*C

rc_candies = []

for i in range(N):
    r, c = map(int, input().split())
    r_candies[r-1] += 1
    c_candies[c-1] += 1  
    rc_candies.append([r, c])  
    
r_sums = collections.Counter(r_candies)
c_sums = collections.Counter(c_candies)

cnt_ans = 0
for i in range(K+1):
    cnt_ans += r_sums[i]*c_sums[K-i]
    
for i in range(N):
    cnt_candies = r_candies[rc_candies[i][0]-1] + c_candies[rc_candies[i][1]-1]
    
    if cnt_candies == K:
        cnt_ans -= 1
    elif cnt_candies == K+1:
        cnt_ans += 1 
        
print(cnt_ans)