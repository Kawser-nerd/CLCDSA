lists = input().split()
a = int(lists[0])
b = int(lists[1])
x = int(lists[2]) * 2
answer  = []
next = 0
for num in range(0, x):
    if(a == b):
        answer.append(a)
        break
    answer.append(a)
    answer.append(b)
    a += 1
    b -= 1
    if(len(answer) >= x or a > b or b < 0):
        break
    if(a == b):
        answer.append(a)
        if(a + num < b - num):
            for b_num in range(b, a):
                answer.append(b_num)
                if (len(answer) > x):
                    break
        elif(a + num > b - num):
            for a_num in range(a, b):
                answer.append(a_num)
                if (len(answer) > x):
                    break
        break
answer.sort()
for a in answer:
    print(a)