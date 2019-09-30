#!/usr/bin/env python
# Code of Google Code Jam
# Wentao Han (aerodonkey@gmail.com)

# imports {{{

import copy
import os
import pickle
import select
import sys

# }}}

# input/output routines {{{

_TYPE = {'d': int, 'l': long, 'f': float, 's': str}
_buffer = []

def _refresh_buffer():
    if not _buffer:
        line = sys.stdin.readline()
        _buffer.extend(line.split())

def _next_token(refresh=True):
    if refresh:
        _refresh_buffer()
    if _buffer:
        return _buffer.pop(0)
    else:
        return None

def scanf(format):
    if len(format) % 2 != 0:
        raise ValueError
    for i in xrange(0, len(format), 2):
        if format[i] != '%':
            raise ValueError
        if format[i + 1].isupper() and len(format) != 2:
            raise ValueError
        if format[i + 1].lower() not in _TYPE:
            raise ValueError
    result = []
    if len(format) == 2 and format[1].isupper():
        _refresh_buffer()
        while _buffer:
            token = _next_token(False)
            value = _TYPE[format[1].lower()](token)
            result.append(value)
    else:
        for i in xrange(1, len(format), 2):
            token = _next_token()
            value = _TYPE[format[i]](token)
            result.append(value)
    return tuple(result)

def printf(format, *arguments):
    message = format % arguments
    sys.stdout.write(message)
    return len(message)

def log(format, *arguments):
    message = format % arguments
    sys.stderr.write(message)

# }}}

# utility routines {{{

def enumerations(elements, length):
    def generate_enums():
        if len(enum) == length:
            enums.append(copy.copy(enum))
        else:
            for elm in elements:
                enum.append(elm)
                generate_enums()
                enum.pop()
    enums = []
    enum = []
    generate_enums()
    return enums

def permutations(elements, size=None):
    def generate_perms():
        if (size is not None and len(perm) == size) or len(perm) == len(elements):
            perms.append(copy.copy(perm))
        else:
            for elm in elements:
                if elm not in perm:
                    perm.append(elm)
                    generate_perms()
                    perm.pop()
    perms = []
    perm = []
    generate_perms()
    return perms

# operations with none {{{

def max_none(x, y):
    if y is None:
        return x
    elif x is None:
        return y
    elif y > x:
        return y
    else:
        return x

def min_none(x, y):
    if y is None:
        return x
    elif x is None:
        return y
    elif y < x:
        return y
    else:
        return x

def update_max(x, y):
    if y is None:
        return (x, False)
    elif x is None:
        return (y, True)
    elif y > x:
        return (y, True)
    else:
        return (x, False)

def update_min(x, y):
    if y is None:
        return (x, False)
    elif x is None:
        return (y, True)
    elif y < x:
        return (y, True)
    else:
        return (x, False)

def neg_none(x):
    if x is None:
        return None
    else:
        return -x

def add_none(x, y):
    if x is None or y is None:
        return None
    else:
        return x + y

def sub_none(x, y):
    if x is None or y is None:
        return None
    else:
        return x - y

def mul_none(x, y):
    if x is None or y is None:
        return None
    else:
        return x * y

def div_none(x, y):
    if x is None or y is None:
        return None
    else:
        return x / y

def mod_none(x, y):
    if x is None or y is None:
        return None
    else:
        return x % y

# }}}

def make_array(dimension, value=None):
    if type(dimension) is int:
        dimension = (dimension,)
    if len(dimension) <= 0:
        array = None
    elif len(dimension) == 1:
        array = [value] * dimension[0]
    elif len(dimension) == 2:
        array = [[value] * dimension[1] for i in xrange(dimension[0])]
    elif len(dimension) == 3:
        array = [[[value] * dimension[2] for j in xrange(dimension[1])]
                                         for i in xrange(dimension[0])]
    else:
        dimension = list(dimension)[::-1]
        array = [value] * dimension[0]
        for dim in dimension[1:]:
            outer_array = [None] * dim
            for i in xrange(dim):
                outer_array[i] = copy.deepcopy(array)
            array = outer_array
    return array

# }}}

def check(large, small, perm):
    for u, v in small:
        u2 = perm[u]
        v2 = perm[v]
        if (u2, v2) not in large and (v2, u2) not in large:
            return False
    return True

def input(case_num):
    N, = scanf('%d')
    large = []
    for i in xrange(N - 1):
        u, v = scanf('%d%d')
        large.append((u - 1, v - 1))
    M, = scanf('%d')
    small = []
    for i in xrange(M - 1):
        u, v = scanf('%d%d')
        small.append((u - 1, v - 1))
    return (N, large, M, small)

def output(case_num, output_set):
    printf('Case #%d: %s\n', case_num + 1, output_set)

def solve(input_set):
    N, large, M, small = input_set
    # log('%d %d\n', N, M)
    perms = permutations(range(N), M)
    for perm in perms:
        # log('%s\n', perm)
        if check(large, small, perm):
            answer = 'YES'
            break
    else:
        answer = 'NO'
    return answer

# main {{{

_LENGTH_WIDTH = 10

def _read(fd, size):
    buffer = ''
    while len(buffer) < size:
        buffer += os.read(fd, size - len(buffer))
    return buffer

def _write(fd, data):
    orignal_size = len(data)
    while data:
        size = os.write(fd, data)
        data = data[size:]
    return orignal_size

class _Worker:

    def __init__(self, id, pid, rfd, wfd):
        self.id = id
        self.pid = pid
        self.rfd = rfd
        self.wfd = wfd
        self.case_num = None

    def fileno(self):
        return self.rfd

    def send(self, message):
        data = pickle.dumps(message)
        length = str(len(data)).zfill(_LENGTH_WIDTH)
        _write(self.wfd, length)
        _write(self.wfd, data)

    def receive(self):
        length = int(_read(self.rfd, _LENGTH_WIDTH))
        data = _read(self.rfd, length)
        message = pickle.loads(data)
        return message

def _run_as_worker(rfd, wfd):
    worker = _Worker(None, None, rfd, wfd)
    input_set = worker.receive()
    while input_set is not None:
        output_set = solve(input_set)
        worker.send(output_set)
        input_set = worker.receive()
    os.close(rfd)
    os.close(wfd)
    os._exit(0)

def _run_as_master(num_workers):
    workers = []
    for i in xrange(num_workers):
        mw_rfd, mw_wfd = os.pipe()
        wm_rfd, wm_wfd = os.pipe()
        pid = os.fork()
        if pid == 0:
            os.close(mw_wfd)
            os.close(wm_rfd)
            _run_as_worker(mw_rfd, wm_wfd)
        os.close(mw_rfd)
        os.close(wm_wfd)
        worker = _Worker(i, pid, wm_rfd, mw_wfd)
        workers.append(worker)
    num_cases, = scanf('%d')
    output_sets = make_array(num_cases)
    case_num = 0
    num_finished_cases = 0
    while num_finished_cases < num_cases:
        if case_num < num_cases:
            idle_workers = [worker for worker in workers
                                   if worker.case_num is None]
            idle_workers = idle_workers[:num_cases - case_num]
            for worker in idle_workers:
                input_set = input(case_num)
                worker.send(input_set)
                worker.case_num = case_num
                case_num += 1
        ready_workers, dummy1, dummy2 = select.select(workers, [], [])
        for worker in ready_workers:
            output_set = worker.receive()
            output_sets[worker.case_num] = output_set
            log('Case #%d (worker %d): %s\n',
                worker.case_num + 1, worker.id, output_set)
            worker.case_num = None
            num_finished_cases += 1
    for case_num, output_set in enumerate(output_sets):
        output(case_num, output_set)
    for worker in workers:
        worker.send(None)
    for worker in workers:
        os.close(worker.rfd)
        os.close(worker.wfd)
        os.waitpid(worker.pid, 0)

def _run_as_single():
    num_cases, = scanf('%d')
    for case_num in xrange(num_cases):
        input_set = input(case_num)
        output_set = solve(input_set)
        log('Case #%d (single): %s\n', case_num + 1, output_set)
        output(case_num, output_set)

if __name__ == '__main__':
    try:
        num_workers = int(sys.argv[1])
    except IndexError, ValueError:
        num_workers = 0
    if num_workers < 0:
        num_workers = 0
    if num_workers == 0:
        _run_as_single()
    else:
        _run_as_master(num_workers)

# }}}

# vim: et ts=8 sts=4 sw=4 fdm=marker
