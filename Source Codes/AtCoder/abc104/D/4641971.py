X = list(input())

q_num = X.count("?")
a_num = 0
c_num = X.count("C")
left_q_num = 0
right_q_num = q_num
ans = 0
len_x = len(X)
q_dict = []
b_ans = 0
q_ans = 0
q_dict = {}
q_dict[q_num - 1] = (3 ** (q_num - 1)) % (10 ** 9 + 7)
q_dict[q_num - 2] = (3 ** (q_num - 2)) % (10 ** 9 + 7)
q_dict[q_num - 3] = (3 ** (q_num - 3)) % (10 ** 9 + 7)
q_dict[q_num] = (3 ** (q_num)) % (10 ** 9 + 7)

if X[0] == "?":
    right_q_num -= 1
elif X[0] == "C":
    c_num -= 1
for i, x in enumerate(X):
    if x == "B" or x == "?":
        ans += (a_num * c_num)  * (q_dict[(left_q_num + right_q_num)])
        if left_q_num + right_q_num >= 2:
            ans += (right_q_num * left_q_num  + 3*(left_q_num * c_num) + 3*(right_q_num * a_num)) * (q_dict[(left_q_num + right_q_num - 2)])
        elif left_q_num + right_q_num == 1:
            ans += ((left_q_num * c_num) + (right_q_num * a_num)) * (q_dict[(left_q_num + right_q_num - 1)])
        ans = ans % (10 ** 9 + 7)
    if  i == len_x - 1:
        break
    if x == "A":
        a_num += 1
    elif x == "?":
        left_q_num += 1
    if X[i + 1] == "C":
        c_num -= 1
    elif X[i + 1] == "?":
        right_q_num -= 1

print(ans % (10 ** 9 + 7))