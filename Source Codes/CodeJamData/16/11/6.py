from sys import stdin, stdout

def solve(test_id):
    s = stdin.readline().strip()

    r = ''
    
    for a in s:
        if len(r) > 0 and r[0] <= a:
            r = a + r
        else:
            r = r + a

    print("Case #{}: {}".format(test_id, r))

def main():
    t = int(stdin.readline())
    for i in range(t):
        solve(i+1)

main()
