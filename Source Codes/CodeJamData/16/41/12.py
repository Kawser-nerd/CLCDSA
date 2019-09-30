from sys import stdin
import collections
import functools

DEBUG = False


def debug_print(*args):
    if DEBUG:
        print args

def find_winner(S, R, P):

    if S == 1 and R == 0  and P == 0:
        return 'S'
    if S == 0 and R == 1 and P == 0:
        return 'R'
    if S == 0 and R == 0 and P == 1:
        return 'P'

    N = S + R + P
    if S > N/2 or R > N/2 or P > N/2:
        return False

    S_1 = 0
    R_1 = 0
    P_1 = 0

    if S <= R and S <= P:
        if P > R:
            S_1 = P - R
            S -= S_1
            P -= S_1
        else:
            R_1 = R - P
            S -= R_1
            R -= R_1
        S_1 += S/2
        R_1 += S/2
        P_1 = N/2 - S_1 - R_1
        debug_print('1:', R_1,P_1,S_1)

    elif R <= S and R <= P:
        if S > P:
            R_1 = S - P
            S -= R_1
            R -= R_1
        else:
            P_1 = P - S
            P -= P_1
            R -= P_1
        R_1 += R/2
        P_1 += R/2
        S_1 = N/2 - R_1 - P_1
        debug_print('2:', R_1,P_1,S_1)

    else:
        if R > S:
            P_1 = R - S
            P -= P_1
            R -= P_1
        else:
            S_1 = S - R
            S -= S_1
            P -= S_1
        P_1 += P/2
        S_1 += P/2
        R_1 = N/2 - P_1 - S_1
        debug_print('3:', R_1,P_1,S_1)

    return find_winner(S_1, R_1, P_1)

def bracket_from_winner(winner, N):
    if N == 0:
        return winner

    if winner == 'R':
        if N == 1:
            return ['S','R']
        else:
            return [bracket_from_winner('S', N-1), bracket_from_winner('R', N-1)]
    if winner == 'P':
        if N == 1:
            return ['P','R']
        else:
            return [bracket_from_winner('P', N-1), bracket_from_winner('R', N-1)]
    if winner == 'S':
        if N == 1:
            return ['P','S']
        else:
            return [bracket_from_winner('P', N-1), bracket_from_winner('S', N-1)]

def bracket_sort(bracket):
    if bracket in ('R', 'S', 'P'):
        return bracket

    b1 = bracket_sort(bracket[0])
    b2 = bracket_sort(bracket[1])

    if b1 < b2:
        return b1 + b2
    else:
        return b2 + b1

def main():
    num_cases = int(stdin.readline())
    for case in range(1, num_cases + 1):

        N, R, P, S = map(int, stdin.readline().split())

        debug_print('input', R, P, S)

        winner = find_winner(S, R, P)
        if not winner:
            print "Case #{}: IMPOSSIBLE".format(case)
            continue

        debug_print(winner)
        bracket = bracket_from_winner(winner, N)
        debug_print(bracket)

        first_bracket = bracket_sort(bracket)
        debug_print(first_bracket)

        print "Case #{}: {}".format(case, first_bracket)

if __name__ == "__main__":
    main()
