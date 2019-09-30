def solve(message):
    time = 0
    base = max(2, len(set(message)))
    digits = range(base)
    digits.remove(1)
    digits.reverse()
    symbols = {message[0]: 1}
    for symbol in message:
        time *= base
        if symbol not in symbols:
            symbols[symbol] = digits.pop()
        time += symbols[symbol]
    return time

def main():
    T = int(raw_input())
    for case in xrange(T):
        message = raw_input()
        print 'Case #%d: %d' % (case + 1, solve(message))

if __name__ == '__main__':
    main()
