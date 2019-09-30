#coding=UTF-8

import sys
#if digit(a)==digit(b) then
# a <= b <=> a <=_{str} b
# easy nomal

# 1. serch digit(N)
# 2. serch N

#note '0' < '1' < '2'

# utopian when N=123
# ? 1     => Y
# ? 12    => Y
# ? 123   => Y
# ? 1230  => N

# most cases
# ? 100   => Y
# ? 1000  => N
# ==> 3 digits!

# when N=10^c
# no jump (...,{<=,<=_{str}},{>,>_{str}},...)
# => Try 9,99,999,9999,...
# or 11 101 1001 whatsoever...
# always str(N) <= '9'*c

# ? 10**18 is allowed tho N<10**9
# 1 10 100 1000,... are least str for most N (n <=_{str} N)
# In such case, 2nd cond is never true

ans=None
for idx in range(0,11,1):
    print('? 1'+'0'*idx)
    sys.stdout.flush()
    kekka=input()
    if kekka=='N':
        digits=idx
        break
else:
    # 10**c case
    for idx in range(1,11,1):
        print('? '+'9'*idx)
        sys.stdout.flush()
        kekka=input()
        if kekka=='Y':#no cross
            c=idx-1
            break
    ans='! 1'+'0'*c

if ans==None:
    #other case
    #To fix one cmp, query str(guess_number)+'0'
    #so that always n > N

    # if responce == 'Y'
    # myon+'0' >_{str} N
    # i.e. myon >= N (note that boundary)
    kagen=10**(digits-1) # known highest false
    jogen=10**(digits)-1 # known lowest true
    while jogen-kagen>1: # i.e. #not_sure !=0
        miru=(jogen+kagen)//2
        print('? '+str(miru)+'0')
        sys.stdout.flush()
        kekka=input()
        if kekka=='Y':
            jogen=miru
        else:
            kagen=miru

    ans='! '+str(jogen)
            

print(ans)