S = input()

length = len(S)
set_length = len(set(S))

if length == set_length:
    print('yes')
else:
    print('no')