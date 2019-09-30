N = int(input())
mod = 5


def prime_sieve_mod(n):
    _sieve = list(range(2, n + 1))
    _sieve.reverse()
    _prime = []
    while _sieve and len(_prime) < N:
        _num = _sieve.pop()
        if _num % mod == 1:
            _prime.append(_num)
        _del = []
        for _i, _v in enumerate(_sieve):
            if _v % _num == 0:
                _del.append(_i)
        _del.reverse()
        for _i in _del:
            del _sieve[_i]
    return _prime


prime_list = prime_sieve_mod(1381)

print(*prime_list)