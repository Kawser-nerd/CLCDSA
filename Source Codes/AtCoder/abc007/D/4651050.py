import re

def count_valids(n):
    n_str = str(n)

    if "4" in n_str:
        result = re.search("4[0-9]*", n_str)
        s, e = result.span()
        n_str = n_str[:s] + "3" + "8" * (e - s - 1)
    if "9" in n_str:
        result = re.search("9[0-9]*", n_str)
        s, e = result.span()
        n_str = n_str[:s] + "8" * (e - s)
    
    old_digits = "5678"
    new_digits = "4567"
    
    for i in range(4):
        if old_digits[i] in n_str:
            n_str = re.sub(old_digits[i], new_digits[i], n_str)
    
    return int(n_str, 8)

a, b = map(int, input().split())
print((b - a + 1) - (count_valids(b) - count_valids(a - 1)))