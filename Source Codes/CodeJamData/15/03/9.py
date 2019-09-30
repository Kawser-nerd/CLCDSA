TABLE = {
    '1': { '1': '+1', 'i': '+i', 'j': '+j', 'k': '+k' },
    'i': { '1': '+i', 'i': '-1', 'j': '+k', 'k': '-j' },
    'j': { '1': '+j', 'i': '-k', 'j': '-1', 'k': '+i' },
    'k': { '1': '+k', 'i': '+j', 'j': '-i', 'k': '-1' }
}

def main():
    num_cases = input()
    for case in range(num_cases):
        m = int(raw_input().split()[1])
        part = raw_input()
        answer = 'YES' if possible(part, m) else 'NO'
        print 'Case #%d: %s' % (case + 1, answer)

def possible(part, m):
    if m > 12:
        m = 12 + m % 4
    s = part * m

    i_block = get_block(s, '+i')
    if i_block == None: return False
    s = s[i_block:]

    j_block = get_block(s, '+j')
    if j_block == None: return False
    s = s[j_block:]

    k_block = get_block(s, '+k')
    if k_block == None: return False
    s = s[k_block:]

    rem = '+1'
    for c in s:
        rem = mult(rem, '+' + c)
    return rem == '+1'

def get_block(s, target):
    product = '+1'
    for i, c in enumerate(s):
        product = mult(product, '+' + c)
        if product == target:
            return i + 1
    return None

def exp(q, e):
    result = '+1'
    for i in range(e):
        result = mult(result, q)
    return result

def mult(a, b):
    a_sign, a_sym = list(a)
    b_sign, b_sym = list(b)
    sign, sym = list(TABLE[a_sym][b_sym])
    sign = '-' if (a_sign, b_sign, sign).count('-') % 2 else '+'
    return sign + sym

def mult_many(s):
    product = '+1'
    for c in s:
        product = mult(product, '+' + c)
    return product

if __name__ == '__main__':
    main()
