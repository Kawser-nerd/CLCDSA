a, b = map(int, input().split())
dis = abs(b-a)
ans1 = int(dis / 10)
ex = dis % 10
if(ex == 1 or ex == 5):
    ans2 = 1
elif(ex == 3 or ex == 7 or ex == 8):
    ans2 = 3
elif(ex == 0):
    ans2 = 0
else :
    ans2 = 2 
print(ans1 + ans2)