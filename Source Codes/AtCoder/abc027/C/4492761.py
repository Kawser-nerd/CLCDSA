n = int(input())
k = len(bin(n)) - 2
 
t = 0
x = 1
while x <= n:
    t += 1
    if (t % 2) ^ (k % 2):
        x = x * 2
    else:
        x = x * 2 + 1
        
print('Aoki' if t % 2 else 'Takahashi')