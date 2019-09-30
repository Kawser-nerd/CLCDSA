#12
n = int(input())
h = n//3600
n = n-h*3600
m = n//60
s = n-m*60

if h<10:
    print('0'+str(h)+':', end='')
else:
    print(str(h)+':', end='')

if m<10:
    print('0'+str(m)+':', end='')
else:
    print(str(m)+':', end='')

if s<10:
    print('0'+str(s), end='')
else:
    print(str(s), end='')
    
print()