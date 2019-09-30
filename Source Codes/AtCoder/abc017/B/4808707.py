choku = ['ch','o','k','u']
s = input()
def f(i):
    if i == len(s):
        return True
    elif s[i] in choku:
        return f(i + 1)
    elif s[i:i+2] in choku:
        return f(i + 2)
    else:
        return False
print('YES' if f(0) else 'NO')