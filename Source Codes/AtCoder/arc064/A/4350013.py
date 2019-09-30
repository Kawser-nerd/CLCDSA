N,x=map(int,input().split())
candies = list(map(int,input().split()))
count = 0
for i in range(len(candies)):
    if i == 0:
        if candies[i] > x:
            count += candies[i] - x
            candies[i] = x
    else:
        if candies[i-1] + candies[i] > x:
            count += candies[i-1] + candies[i] - x
            candies[i] = candies[i] - (candies[i-1] + candies[i] - x)
print(count)