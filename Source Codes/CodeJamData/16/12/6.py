from sys import stdin, stdout

def solve(test_id):
    n = int(stdin.readline())
    
    a = []
    for i in range(n*2-1):
        a.extend(int(x) for x in stdin.readline().split())
    
    a = sorted(a)
    r = []
    
    i = 0
    while i < len(a):
        if i+1 < len(a) and a[i] == a[i+1]:
            i += 2
        else:
            r.append(a[i])
            i += 1
    
    print("Case #{}:".format(test_id), *r)

def main():
    t = int(stdin.readline())
    for i in range(t):
        solve(i+1)

main()
