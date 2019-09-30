S = input()

redcount = S.count('0')
bluecount = S.count('1')

mincount = min(redcount,bluecount)
answer = mincount*2

print(answer)