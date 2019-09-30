from fractions import gcd
name = "A-large"
f_in = open(name + '.in',"r")
f_out = open(name + '.out','w')


                                  
T  =  int(f_in.readline())    
for i in range(T):
        print(i)
        N , Pd, Pg =  [int(x) for x in (f_in.readline().split())]


        if(Pg == 100 and Pd != 100):
                f_out.write("Case #" +str(i+1) + ": " +str("Broken")+"\n")
        elif(Pg == 100):
                f_out.write("Case #" +str(i+1) + ": " +str("Possible")+"\n")
        elif(Pg == 0 and Pd != 0):
                f_out.write("Case #" +str(i+1) + ": " +str("Broken")+"\n")
        elif(Pg == 0):
                f_out.write("Case #" +str(i+1) + ": " +str("Possible")+"\n")
        elif(Pd == 0):
                f_out.write("Case #" +str(i+1) + ": " +str("Possible")+"\n")
        elif(Pd == 100):
                f_out.write("Case #" +str(i+1) + ": " +str("Possible")+"\n")
        else:
                ret = False
                #for x in range(N):
                #        if((x*100)%Pd == 0 and x*100%(100 - Pd) == 0):
                #                ret = True
                #                break

                g1 = max(100//gcd(Pd,100),100//gcd(100 - Pd,100))
                print(g1,N)
                if(g1 <= N):
                        f_out.write("Case #" +str(i+1) + ": " +str("Possible")+"\n")
                else:
                        f_out.write("Case #" +str(i+1) + ": " +str("Broken")+"\n")              
                        
                        
        



                
f_in.close()
f_out.close()
