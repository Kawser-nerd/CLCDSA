import itertools as it

S = input()
plus_list = S.split('+')
no_zero_count = 0
for s in plus_list :
    if (s.count("0") == 0) :
        no_zero_count += 1

print(no_zero_count)