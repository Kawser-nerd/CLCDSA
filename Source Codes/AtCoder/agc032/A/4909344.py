# ??????????https://qiita.com/orange_u/items/3f0fb6044fd5ee2c3a37

# ***.py a b c????????
# import sys
#
# args = sys.argv
#
# num_len = int(args[1])
# a = []
# b = []
# N = 100
# # b = [1,2,1]
# for i in range(2, 2+num_len):
#     b.append(int(args[i]))
# print(b)

a = []
# print('input:')
num_len = int(input())
b = list(map(int, input().split()))
# print('--'*len(b))
# print('output:')
# print(b)
N = 100



# for i in range(len(b)):
for i in range(num_len):
    # try:
    #     # print(i)
    #     a.insert(b[i], b[i])
    #     print(a)
    # except:
    #     print(-1)

    if b[i]-1 <= len(a):
        # print(i)
        a.insert(b[i]-1, b[i])
        # print(a)
        flag = True
    else:
        flag = False
        break


if flag:
    for i in a:
        print(i)
else:
    print(-1)