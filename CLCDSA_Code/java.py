import re
import os
import pandas as pd

def parser_mat1(filepath):
    mylines = []
    linenum = 0
    count = 0
    pat = re.compile(r"(localVariableDeclaration) (\-)\w*")
    pat1 = re.compile(r"\bunann\w*\b")

    with open(filepath,'r') as file_object:
        lines = file_object.readlines()
        for i in range(0,len(lines)):
            line = lines[i]
        #for line in file_object:
            linenum += 1
            if pat.search(line) != None:
                #print(lines[i+1])
                if pat1.search(lines[i+1]) == None:
                    count += 1
                    mylines.append((linenum, line.rstrip('\n')))
    #for err in mylines:
     #   print("Line " + str(err[0]) + ": " + err[1])
    return count

def parser_mat2(filepath):
    #myexpressions = []
    linenum = 0
    count = 0
    pat = re.compile(r"(expressionStatement) (\-)\w*")
    #pat1 = re.compile(r"\bunan\w*\b")

    with open(filepath,'r') as file_object:
        lines = file_object.readlines()
        for i in range(0,len(lines)):
            line = lines[i]
        #for line in file_object:
            linenum += 1
            if pat.search(line) != None:
                #print(lines[i+1])
                #if pat1.search(lines[i+1]) == None:
                count += 1
                myexpressions.append((linenum, line.rstrip('\n')))
    #for err in myexpressions:
     #   print("Line " + str(err[0]) + ": " + err[1])
    return count

def parser_mat3(filepath):
    mylines = []
    linenum = 0
    count = 0
    param = []
    pat = re.compile(r"(methodDeclarator) (\-)\w*")
    pat1 = re.compile(r"\bformal\w*\b")

    with open(filepath,'r') as file_object:
        lines = file_object.readlines()
        for i in range(0,len(lines)):
            line = lines[i]
        #for line in file_object:
            linenum += 1
            if pat.search(line) != None:
                #print(lines[i+1])
                if pat1.search(lines[i+1]) != None:
                #count += 1
                    ct = linenum + 1
                    mylines.append((ct, lines[i+1].rstrip('\n')))
    for err in mylines:
       # print("Line " + str(err[0]) + ": " + err[1])
        mt = err[1].partition("->")
        #print(mt)
        xt = mt[2].split(",")
        param.append(xt)
        count += len(xt)
    #print(param)
    return count

def parser_mat4():#filepath):
    mylines = []
    ops = "\|\||/=|\*=|\+=|-=|%=|>>>=|>>=|<<=|&=|\^=|\|=|==|!=|<=|>=|\++|--|<<|>>>|>>|&&|!|=|-|\+|\*|/|%|>|<|&|\||\^|~|\?"
    linenum = 0
    mcount = 0
    count1 = 0
    #pat = re.compile(r"(localVariableDeclaration) (\-)\w*")
    pat1 = re.compile(r"\b\w*PRINT|print|Print\w*\b")

    #with open(filepath,'r') as file_object:
     #   lines = file_object.readlines()
    for i in range(0,len(myexpressions)):
        line = myexpressions[i]
        #for line in file_object:
        linenum += 1
        mt = line[1].partition("->")
        #mcount += 1
        ft = ''.join(mt[2])
        #print("\n" + str(ft))
        if(pat1.search(ft)==None):
            xt = re.split(ops,ft)
            ot = len(xt) - 1
            mcount = mcount + ot
            #print("#split  :   " + str(len(xt)) + "   #Operator   :   " + str((len(xt)-1)))
            #print(xt)
            #if(ot > 0):
             #   count1 = count1 + len(xt)
            myoperators.append((linenum, xt, ft.strip('\n')))
    #print(mcount)
    #print(myoperators)
    return mcount  # , count1


"""    for i in range(0, len(mylines)):
        line = mylines[i]
        n = line[1]
        m = len(n) -1
        x = []

        print("****" + str(len(n)) + "+++++" + str(m))
        for j in range(0, m):
            print(n[j])
            x.append(n[j])
            print(n)
            print(n[j])
        myoperators.append(x)
   """
    #print(mylines)

            #myoperators.append(xt)
    #print(mylines)
   # for err in mylines:
    #    print("Line " + str(err[0]) + ": " + err[1]+ err[2])
    #print(mylines)
    #print(myoperators)
    #f = myoperators[15]
    #print(len(f[1]))



def parser_mat5():#filepath):
    mylines = []
    linenum = 0
    operand = []
    operand1 = []
    count = 0
    count1 = 0
    op = "\."
    ops = "\]\[|\[|:"
    ct = ""

    for i in range(0, len(myoperators)):
        line = myoperators[i]
        # for line in file_object:
        linenum += 1
        mt = line[1]
        #print("\n Split   " + str(i) + "   " + str(mt) + "\n")
        for j in range(0, len(mt)):
            #print("\t Operand   :" + str(mt[j]))
            #print(mt[j])
            ct = re.split(op, mt[j])
            count1 = count1 + len(ct)
            #print(ct)
            operand1.append((ct))
    #print("i am doomed")
    #print(myoperators)
    #print(operand1)
    for i in range(0, len(operand1)):
        line = operand1[i]
        mt = line

        #print("\n Split   " + str(i) + "   " + str(mt) + "\n")
        for j in range(0, len(mt)):
            #print("\t Operand   :" + str(mt[j]))
            ct = mt[j]
            m = re.compile(r"\b\w*\(\)\w*")
            #m1 = re.compile(r"\b\w*\(\)\;")
            if(m.search(ct)== None): # or m1.search(ct)== None):
                m2 = re.compile(r"\b\w*\(")
                if (m2.search(ct) != None):
                    #print("before     " + ct )
                    ct = m2.sub('',ct)
                #ct=str(ct)
                    #print("    after    " + ct)

                ct = re.split(ops, ct)
                lt = len(ct)
            #if(lt > 0):
                count = count + lt
                #print("  " + str(lt) + "   " + str(ct))
                operand.append((ct))
            else:
                print("Not an operand")
            #else:
                #print("*** EOF ++++ " + ct)
#                print(ct)
        """    for i in range(0,len(myoperators)):
                line = myoperators[i]
                linenum += 1
                mt = line[1]
                print("\n Split   " + str(i) + "   " + str(mt) + "\n")
                for j in range(0,len(mt)):
                    print("\t Operand   :" + mt[j])
                    print(mt[j])
                    #nt = ''.join(mt[j])
                    xt = re.split(ops,mt[j])
                    operand.append((xt))
                #if pat.search(line) != None:
                        #print(lines[i+1])
                 #       if pat1.search(lines[i+1]) == None:
                    lt = len(xt)
                    #count = count + lt
                    print("\n#Operand   :   " + str((lt)) + "   " + str(xt))
        """
    #print(operand)
    #print(len(operand))
    return count


def parser_mat6(filepath):
    mylines = []
    linenum = 0
    count = 0
    pat = re.compile(r"(basicForStatement) (\-)\w*")
    pat1 = re.compile(r"(whileStatement) (\-)\w*")

    with open(filepath,'r') as file_object:
        lines = file_object.readlines()
        for i in range(0,len(lines)):
            line = lines[i]
        #for line in file_object:
            linenum += 1
            if ((pat.search(line) != None)or(pat1.search(line) != None)):
                #print(lines[i+1])
                #if pat1.search(lines[i+1]) == None:
                count += 1
                mylines.append((linenum, line.rstrip('\n')))
    #for err in mylines:
        #print("Line " + str(err[0]) + ": " + err[1])
    return count

def parser_mat7(filepath):
    mylines = []
    linenum = 0
    count = 0
    pat = re.compile(r"(catchClause) (\-)\w*")
    pat1 = re.compile(r"(throwStatement) (\-)\w*")

    with open(filepath,'r') as file_object:
        lines = file_object.readlines()
        for i in range(0,len(lines)):
            line = lines[i]
        #for line in file_object:
            linenum += 1
            if ((pat.search(line) != None) or (pat1.search(line) != None)):
                #print(lines[i+1])
                #if pat1.search(lines[i+1]) == None:
                count += 1
                mylines.append((linenum, line.rstrip('\n')))
    #for err in mylines:
        #print("Line " + str(err[0]) + ": " + err[1])
    return count

def parser_mat8(filepath):
    mylines = []
    linenum = 0
    count = 0
    pat = re.compile(r"(catchClause) (\-)\w*")
    pat1 = re.compile(r"(variableDeclaratorId) (\-)\w*")

    with open(filepath,'r') as file_object:
        lines = file_object.readlines()
        for i in range(0,len(lines)):
            line = lines[i]
        #for line in file_object:
            linenum += 1
            if pat.search(line) != None:
                #print(lines[i+1])
                if pat1.search(lines[i+3]) != None:
                    count += 1
                    mylines.append((linenum, line.rstrip('\n')))
    #for err in mylines:
        #print("Line " + str(err[0]) + ": " + err[1])
    return count


"""def parser_mat9(filepath):
    mylines = []
    linenum = 0
    count = 0
    pat = re.compile(r"(localVariableDeclaration) (\-)\w*")
    pat1 = re.compile(r"\bunan\w*\b")

    with open(filepath,'r') as file_object:
        lines = file_object.readlines()
        for i in range(0,len(lines)):
            line = lines[i]
        #for line in file_object:
            linenum += 1
            if pat.search(line) != None:
                #print(lines[i+1])
                if pat1.search(lines[i+1]) == None:
                    count += 1
                    mylines.append((linenum, line.rstrip('\n')))
    for err in mylines:
        print("Line " + str(err[0]) + ": " + err[1])
    return count
"""

if __name__ == '__main__':
    myfile = []
    vt = re.compile("\.java")
    for file in os.listdir("D:/CloneData/AtCoder/abc003/B/"):
        result = []
        if file.endswith(".java"):
            #print(file)
            #print(vt.sub(".txt", file))
            myfile.append(os.path.join("D:/CloneData/AtCoder/abc003/B/", vt.sub(".txt", file)))

    print(myfile)
    #filepath = 'D:/CloneData/AtCoder/abc003/A/4440517.txt'
    #filepath = 'D:/CloneData/AtCoder/abc003/B/4434384.txt'

    #Variables declared
    for filepath in myfile:
        #filepath = 'D:/CloneData/AtCoder/abc003/B/4434384.txt'
        myexpressions = []
        myoperators = []
        data1 = parser_mat1(filepath)
        print("# Variables")
        print(data1)

    #Expressions
        data2 = parser_mat2(filepath)
   # with open("D:/CloneData/test.txt","w") as f:
    #    f.write(str(myexpressions))
        print("# Expressions")
        print(data2)

    #Arguments
        data3 = parser_mat3(filepath)
        print("# Arguments")
        print(data3)

    #Operators
        data4 = parser_mat4()#filepath)
        print("# Operators")
        print(data4)

    #Operands
        data5 = parser_mat5()#filepath)
        print("# Operands")
        print(data5)

    #Loops
        data6 = parser_mat6(filepath)
        print("# loops")
        print(data6)

    #Exceptions
        data7 = parser_mat7(filepath)
        print("# Exceptions")
        print(data7)

    #Exceptions referenced
        data8 = parser_mat8(filepath)
        print("# Exceptions referenced")
        print(data8)

        #result.append((file, data1, data2, data3, data4, data5, data6, data7, data8))
        print(result)

    #data = parser_mat9(filepath)
    #print(data)
        f = open("D:/CloneData/AtCoder/abc003/B/result.txt", "a+")
        f.write("\n" + filepath + "\t" + str(data1) + "\t" + str(data2) + "\t" + str(data3) + "\t" + str(data4) + "\t" + str(data5) + "\t" + str(data6) + "\t" + str(data7) + "\t" + str(data8))
        print(filepath)
        f.close()





