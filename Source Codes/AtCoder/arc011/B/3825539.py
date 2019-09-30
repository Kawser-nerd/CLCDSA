N = int(input())
w = input()

numbers = ""
for i in range(len(w)):
    if w[i] == "b" or w[i] == "c" or w[i] == "B" or w[i] == "C":
        numbers += "1"
    elif w[i] == "d" or w[i] == "w" or w[i] == "D" or w[i] == "W":
        numbers += "2"
    elif w[i] == "t" or w[i] == "j" or w[i] == "T" or w[i] == "J":
        numbers += "3"
    elif w[i] == "f" or w[i] == "q" or w[i] == "F" or w[i] == "Q":
        numbers += "4"
    elif w[i] == "l" or w[i] == "v" or w[i] == "L" or w[i] == "V":
        numbers += "5"
    elif w[i] == "s" or w[i] == "x" or w[i] == "S" or w[i] == "X":
        numbers += "6"
    elif w[i] == "p" or w[i] == "m" or w[i] == "P" or w[i] == "M":
        numbers += "7"
    elif w[i] == "h" or w[i] == "k" or w[i] == "H" or w[i] == "K":
        numbers += "8"
    elif w[i] == "n" or w[i] == "g" or w[i] == "N" or w[i] == "G":
        numbers += "9"
    elif w[i] == "z" or w[i] == "r" or w[i] == "Z" or w[i] == "R":
        numbers += "0"
    elif w[i] == " " and len(numbers) != 0 and numbers[len(numbers)-1] != " ":
        numbers += " "
    
end = len(numbers)
spaces = 0
for i in range(end):
    if numbers[end - 1 - i] == " ":
        spaces += 1
    else:
        break
    
    
print(numbers[:end-spaces])