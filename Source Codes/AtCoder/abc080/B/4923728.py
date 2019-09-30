n=input()
print('Yes' if int(n)%eval('+'.join(list(n)))==0 else 'No')