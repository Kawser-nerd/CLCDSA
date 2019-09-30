N = int(input())
s = input()

def countCommonLetter(X, Y):
    return len(set([x for x in X if x in Y]))

def solve():
    return max ( [countCommonLetter( s[:i], s[i:] ) for i in range(1, N)] )

print( solve() )