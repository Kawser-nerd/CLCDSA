import itertools

num_list = input()
rule = '+-'

for ops in itertools.product(rule, repeat=3):
    ans = '{}{}{}{}{}{}{}'.format(num_list[0], ops[0], num_list[1], ops[1], num_list[2], ops[2], num_list[3])
    res = eval(ans)
    if res == 7:
        print('{}=7'.format(ans))
        break