#a = '3a 2c 3a 35152538272 c2 d21 3 e3 32 e3c 25383030373 a15'

dicts = {'Left': '<', 'Right': '>', 'AtCoder': 'A'}
ans = ''
for index, item in enumerate(input().split()):
    if index == 0:
        ans += dicts.get(item)
    else:
        ans += (' ' + dicts.get(item))

print(ans)