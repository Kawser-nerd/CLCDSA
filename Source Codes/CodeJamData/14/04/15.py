def war(n,k):
    n=[float(block) for block in n.split(" ")]
    k=[float(block) for block in k.split(" ")]

    points=0
    n = reversed(sorted(n))
    for nblock in n:
        if nblock>max(k):
            points+=1
            k.remove(min(k))
        else:
            k.remove(min([block for block in k if block>nblock]))
    return str(points)

def dwar(n,k):
    n=[float(block) for block in n.split(" ")]
    k=[float(block) for block in k.split(" ")]

    points=0
    n = sorted(n)
    for nblock in n:
        if nblock>min(k):
            points+=1
            k.remove(min(k))
        else:
            k.remove(max(k))
    return str(points)

            
            
input_text = open("input.in")
lines = input_text.readlines()
input_text.close()
with open("output", "a") as outputfile:
    for num in range(0,int(lines[0])):
        outputfile.write("Case #"+str(num+1)+": "+dwar(lines[num*3+2],lines[num*3+3])+" "+war(lines[num*3+2],lines[num*3+3])+"\n")
