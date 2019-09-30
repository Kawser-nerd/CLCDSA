c1 = list(map(int, input().rstrip().split()))
c2 = list(map(int, input().rstrip().split()))
c3 = list(map(int, input().rstrip().split()))
answer = 'No'
#a1?????a2,a3,b1,b2,b3?????????
for i in range(101):
    a1 = i
    b1 = c1[0] - a1
    b2 = c1[1] - a1
    b3 = c1[2] - a1
    a2 = c2[0] - b1
    a3 = c3[0] - b1
    c2_2 = a2 + b2
    c2_3 = a2 + b3
    c3_2 = a3 + b2
    c3_3 = a3 + b3
    if c2_2 == c2[1] and c2_3 == c2[2] and c3_2 == c3[1] and c3_3 == c3[2]:
        answer = 'Yes'
        break
print(answer)