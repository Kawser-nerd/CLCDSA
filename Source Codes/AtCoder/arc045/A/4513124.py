dicts = {'Left': '<', 'Right': '>', 'AtCoder': 'A'}

print(
    ''.join([dicts.get(item) if index == 0 else (' ' + dicts.get(item)) for index, item in enumerate(input().split())])
)