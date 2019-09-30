


#F = open('A-small-attempt1.in')
#O = open('A-small-attempt1.out','w')

F = open('A-large.in')
O = open('A-large.out','w')

T = int(F.readline())

print T


    
for case in range(1,T+1):
    n = int(F.readline())
    store = map(int,F.readline().rstrip().split())

    x = sum(store)

    ans = []
    
    maxi = 0
    
    for i in range(x):
        maxi = max(store)
        findex = -1
        sindex = -1

        q = sum(store)

        if q >= 4:
            for j in range(n):
                if findex == -1 and store[j] == maxi:
                    findex = j
                elif sindex == -1 and store[j] == maxi:
                    sindex = j
                


            if sindex != -1:
                store[sindex] -= 1
                store[findex] -= 1
                ans.append(chr(ord('A')+findex)+chr(ord('A')+sindex))
                

            else:
                store[findex] -= 1
                ans.append(chr(ord('A')+findex))

        elif q == 3:
            for j in range(n):
                if findex == -1 and store[j] == maxi:
                    findex = j

            store[findex] -= 1
            ans.append(chr(ord('A')+findex))


        elif q == 2:
            for j in range(n):
                if findex == -1 and store[j] == maxi:
                    findex = j
                elif sindex == -1 and store[j] == maxi:
                    sindex = j
            if sindex != -1:
                store[sindex] -= 1
                store[findex] -= 1
                ans.append(chr(ord('A')+findex)+chr(ord('A')+sindex))

                

            else:
                store[findex] -= 2
                ans.append(chr(ord('A')+findex)+chr(ord('A')+findex))
            break

        elif q == 1:
            for j in range(n):
                if findex == -1 and store[j] == maxi:
                    findex = j

            store[findex] -= 1
            ans.append(chr(ord('A')+findex))
            break

        else:
            break
        

    ans = ' '.join(i for i in ans)
    
    #print ans
    print case


    O.write("Case #%d: %s\n"%(case,ans))

F.close()
O.close()
