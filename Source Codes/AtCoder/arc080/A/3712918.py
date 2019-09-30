N = int(input())
a = list(map(int,input().split()))

four_num = 0
two_num = 0
odd_num = 0
for _ in a:
    if _%4==0:
        four_num+=1
    elif _%2==0:
        two_num+=1
    else:
        odd_num+=1

if odd_num>four_num and two_num>0:
    print("No")
elif odd_num>four_num+1 and two_num==0:
    print("No")
else:
    print("Yes")