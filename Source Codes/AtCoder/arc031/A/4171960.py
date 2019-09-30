Name = input()
print('YES' if all([Name[k] == Name[-1 - k] for k in range(len(Name) // 2)]) else 'NO')