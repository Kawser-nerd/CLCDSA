
inFile = open("intpu1.txt", "r")
outFile = open("output1.txt", "w")

def solve1(NN,Pd,Pg):
    if Pd==100 and Pg == 100:
        return "Possible"
    if Pd==0 and Pg == 0:
        return "Possible"
    
    d=1
    while d <= NN:
        if (d * Pd) % 100 == 0:
            if Pg < 100 and Pg > 0:
                print (NN,Pd,Pg)
                return "Possible"
                break;
        d+=1
        
    return "Broken";

N = int(inFile.readline())
cnt = 0
for line in inFile:
    cnt+=1
    llLine = line.split()
    
    NN = int(llLine[0])
    Pd = int(llLine[1])
    Pg = int(llLine[2])
    
    result = solve1(NN,Pd,Pg)
    
    resStr = "Case #" + str(cnt) + ": "
    resStr = resStr+ result +"\n"
    print (resStr)
    outFile.write(resStr)
    

def gcd(a,b):
        while a:
                a, b = b%a, a
        return b