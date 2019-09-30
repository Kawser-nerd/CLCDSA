a,b,c = (int(x) for x in input().split())
candy = [a, b, c]
#print(candy)
candy.sort()
#print(candy)
max_candy = candy[2]
middle_candy = candy[1]
min_candy = candy[0]

if max_candy == middle_candy + min_candy:
    print('Yes')
else:
    print('No')