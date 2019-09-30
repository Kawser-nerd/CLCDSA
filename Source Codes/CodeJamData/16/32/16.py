
    

    
#7:35pm =.=

#F = open('B-small-attempt1.in')
#O = open('B-small-attempt1.out','w')

F = open('B-large.in')
O = open('B-large.out','w')

T = int(F.readline())

print T


for case in range(1,T+1):
    B,M = map(int,F.readline().rstrip().split())
    temp = M

    #
    binary = []
    while M > 0:
        binary.append(str(M%2))
        M /= 2

    #print binary
    
    if temp > 2**(B-2):
        O.write("Case #%d: %s\n"%(case,'IMPOSSIBLE'))
        #print 'IMPOSSIBLE'
    elif temp < 2**(B-2):
        O.write("Case #%d: %s\n"%(case,'POSSIBLE'))

        if B > 2:
            ans = '0'+'1'*(B-2)+'0'
            O.write("%s\n"%(ans))
            #print ans
            
            for i in range(1,B):
                ans = ''
                for j in range(B):
                    if j <= i:
                        ans += '0'
                    elif j == B-1:
                        if i-1 >= len(binary):
                            ans += '0'
                        else:
                            ans += binary[i-1]
                    else:
                        ans += '1'
                O.write("%s\n"%(ans))
                #print ans
        else:
            O.write("01\n")
            O.write("00\n")
            
    else:
        O.write("Case #%d: %s\n"%(case,'POSSIBLE'))
        for i in range(B):
            ans = ''
            for j in range(B):
                if j <= i:
                    ans += '0'
                else:
                    ans += '1'
            O.write("%s\n"%(ans))
            #print ans



    #O.write("Case #%d: %s\n"%(case,ans))

F.close()
O.close()
