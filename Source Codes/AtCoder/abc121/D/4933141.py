A, B = map(int, input().split())

def cal_xor(X):
    X = X+1
    xor_sum = 0
    digit = 1
    while digit < X:
        digit *= 2
        bit_count = (X // digit) * (digit // 2)
        bit_count += max(0, (X % digit) - (digit // 2))
        
        if bit_count % 2 == 1:
            xor_sum += digit // 2
    
    return xor_sum
        

ans = cal_xor(A-1) ^ cal_xor(B)
print(ans)