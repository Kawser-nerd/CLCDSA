import sys

cached_in = ""

def next_line():
    global cached_in
    if cached_in:
        res = "".join( cached_in )
        cached_in = ""
        return res

    return sys.stdin.readline().strip()

def next_val():
    global cached_in
    while not cached_in:
        cached_in = sys.stdin.readline().strip()
        cached_in = cached_in.split()
        cached_in.reverse()

    return cached_in.pop()

def next_int():
    return int(next_val())
