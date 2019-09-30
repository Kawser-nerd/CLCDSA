def next_number(digits):
    if len(digits) == 1:
        return None
    if len(digits) == 2:
        return (digits[1], digits[0]) if digits[1] > digits[0] else None
    rearrange = next_number(digits[1:])
    if rearrange is not None:
        digits[1:] = rearrange
        return digits
    larger = [d for d in digits if d > digits[0]]
    if larger:
        min_larger = min(larger)
        taildigits = delone(digits[:], min_larger)
        taildigits.sort()
        taildigits.insert(0, min_larger)
        return taildigits
    return None

def delone(taildigits, n):
    for i in range(len(taildigits)):
        if taildigits[i] == n:
            del taildigits[i]
            break
    return taildigits

with open('B-large.in') as f:
    o = open('bnumberout.txt', 'w')
    cases = int(f.next())
    for i in range(1, cases + 1):
        o.write('Case #%d: ' % i)
        strn = f.next().strip()
        digits = [int(d) for d in strn]
        nextdigits = next_number(digits)
        if nextdigits is None:
            leader = min([d for d in digits if d > 0])
            digits = delone(digits, leader)
            digits.sort()
            nextdigits = [leader, 0] + digits
        nextnumber = ''.join([str(d) for d in nextdigits])
        o.write(nextnumber + '\n')
    o.close()
