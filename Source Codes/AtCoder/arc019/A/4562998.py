S = input()
mp = {
    'O': '0',
    'D': '0',
    'I': '1',
    'Z': '2',
    'S': '5',
    'B': '8',
}

for j, k in mp.items():
    S = S.replace(j, k)
print(S)