inp_file=file("C-small.in")
out_file=file("C-small.out","w")

def solve(line):
    line=[int(c1) for c1 in line.split(" ")]
    card_num,indices=line[:2]
    line=line[2:]
    positions=range(card_num)
    result=[0 for c1 in range(card_num)]
    c1=1 # pocet umistenych karet
    c2=0
    while c1<card_num:
        result[positions[c2]]=c1
        positions.pop(c2)
        c2=(c2+c1)%len(positions)
        c1+=1
    result[result.index(0)]=card_num
    #print result,line
    return " ".join([str(result[c1-1]) for c1 in line])

num=int(inp_file.readline())
for case in range(num):
    line=inp_file.readline()[:-1]+" "+inp_file.readline()[:-1]
    out_file.write("Case #%s: "%(case+1)+solve(line)+"\n")
inp_file.close()
out_file.close()
