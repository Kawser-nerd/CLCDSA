translator =  { \
'y':'a',  \
'n':'b',\
'f':'c',\
'i':'d',\
'c':'e',\
'w':'f',\
'l':'g',\
'b':'h',\
'k':'i',\
'u':'j',\
'o':'k',\
'm':'l', \
'x':'m',\
's':'n', \
'e':'o',  \
'v':'p',\
'z':'q',\
'p':'r', \
'd':'s',\
'r':'t',\
'j':'u', \
'g':'v',\
't':'w',\
'h':'x',\
'a':'y',\
'q':'z' \
}




with open('A-small-attempt0.in', 'r') as fin:
    with open('output.txt', 'w') as fout:
        numcases = int(fin.readline())
        for i in range(1, numcases+1):
            fout.write("Case #")
            fout.write(str(i))
            fout.write(": ")
            line = fin.readline() #readline includes trailing \n
            for k in line:
                if k in translator:
                    fout.write(translator[k])
                elif k.isupper() and k.lower() in translator:
                    print "Hit upper"
                    fout.write(translator[k.lower()].upper())
                else:
                    fout.write(k)
        
