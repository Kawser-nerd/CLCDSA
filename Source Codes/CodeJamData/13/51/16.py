from collections import Counter

def solve(B, N, X):
    
    ans = 0
    for i in range(1, 1002):
        bigger = [j for j in X if j > i]
        remain = 37 - len(bigger)
        if remain == 0: continue
        other_bet = sum(j for j in X if j<=i)
        total_bet = remain * i
        my_bet = total_bet - other_bet
        if my_bet > B: break

        profit =  1.0 * my_bet * (36.0 / remain) - my_bet
        if profit > ans:
            ans = profit

        remain_X = [j for j in X if j <= i]
        remain_X.sort(reverse=True)
        my_remove_bet = 0
        print i, remain_X
        for remove_bucket, other_bet_in_this_bucket in enumerate(remain_X, start=1):
            my_remove_bet += (i - other_bet_in_this_bucket)

            if remove_bucket == remain: break

            my_addition_bet = remove_bucket
            if my_bet + my_addition_bet > B: continue

            profit = 1.0 * (my_bet - my_remove_bet) * 36.0/(remain-remove_bucket) - my_bet - my_addition_bet

            if profit > ans:
                print 'remove bucket ', remove_bucket, ' :', other_bet_in_this_bucket
                print 'my bet', my_bet
                print 'my remove_bet ', my_remove_bet
                print 'profit', profit
                ans = profit
            

    print ans
    return ans


if __name__ == '__main__':

    import sys
    
    input_file = sys.argv[1]
    output_file = input_file[:].replace('.in', '.out')


    f_in = open(input_file, 'r')
    f_out = open(output_file, 'w')

    T, = [int(x) for x in f_in.readline().split()]

    for case in range(1, T+1):
        print 
        print '====================='
        print '    ' + str(case)
        print '====================='

        B, N = [int(x) for x in f_in.readline().split()]
        X = [int(x) for x in f_in.readline().split()]

        # Solve
        ans = solve(B, N, X)

        ## Output
        f_out.write('Case #%d: %s\n' % (case, ans))

        

