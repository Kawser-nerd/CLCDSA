listOutput = list()
listInput = list()
nNum = int(input())
strInput = input()
listInput = strInput.split()



while (len(listInput) > 0) and ((nNum - 1) >= 0):
    if int(listInput[nNum - 1]) == nNum:
        listOutput.insert(0, nNum)
        del listInput[nNum - 1]
        nNum = len(listInput)
        continue
    
    nNum -= 1
# end of while

if len(listInput) == 0:
    while(len(listOutput) > 0):
        print(listOutput.pop(0))
else:
    print('-1')