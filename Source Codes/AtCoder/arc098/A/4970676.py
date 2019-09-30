n = int(input())
s = input()
west = [ 0 for i in range(n+1) ]
east = [ 0 for i in range(n+1) ]
for i in range(1,n+1):
    west[i] = west[i-1]
    east[i] = east[i-1]
    if s[i-1] == 'W':
        west[i] += 1
    if s[i-1] == 'E':
        east[i] += 1

ans = 1e9
for i in range(1,n+1):
    reqd_east_cnt = i-1
    got_east_cnt = east[i-1]
    reqd_west_cnt = n - i
    got_west_cnt = west[n] - west[i]
    # print(reqd_east_cnt,got_east_cnt,reqd_west_cnt,got_west_cnt)
    ans = min( ans, reqd_east_cnt - got_east_cnt + reqd_west_cnt - got_west_cnt)
print(ans)