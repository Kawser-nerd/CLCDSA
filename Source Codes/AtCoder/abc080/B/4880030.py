n = input()
fx = sum(list(map(int,str(n))))
print('Yes' if int(n)%fx == 0 else 'No')