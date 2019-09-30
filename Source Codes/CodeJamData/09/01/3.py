#!/usr/bin/python
import os, sys

def processCase(caseStr, letterData, wordlength):
    # Get the list of words.
    # For the first character, take everything.
    casePos = 0
    allowedWords = set()
    for letterPos in range(wordlength):
        # Parse this case
        allowedLetters = []
        if caseStr[casePos] == '(':
            casePos += 1
            while (caseStr[casePos] != ')'):
                allowedLetters.append(caseStr[casePos])
                casePos += 1
            # Skip past closing ')'
            casePos += 1
        else:
            # Just one char
            allowedLetters.append(caseStr[casePos])
            casePos += 1
        #print "caseStr: %s, lP: %d, allowedLetters: %s" % (caseStr, letterPos, allowedLetters)
        # Now, see which words satisfy any of the letters in here.
        tempWords = set()
        for l in allowedLetters:
            if l in letterData[letterPos]:
                tempWords.update(letterData[letterPos][l])
        #print tempWords
        if letterPos == 0:
            # Create the set
            allowedWords = tempWords
        else:
            # Intersect with existing set
            allowedWords.intersection_update(tempWords)
    return len(allowedWords)


def main(filename):
    fileLines = open(filename, 'r').readlines()
    #print len(fileLines)
    index = 0
    words = []
    [wordlength, numdict, numcases] = [int(x) for x in fileLines[index][:-1].split(' ')]
    # stores a hash of which words have which letters at which positions
    letterPosToWords = [{} for x in range(wordlength)]
    index += 1
    # Read in the words
    for i in range(numdict):
        word = fileLines[index][:-1]
        index += 1
        for j in range(wordlength):
            c = word[j]
            if (not(c in letterPosToWords[j])):
                letterPosToWords[j][c] = set()
            letterPosToWords[j][c].add(word)
        words.append(word)
    # Read in the cases
    for i in range(numcases):
        case = fileLines[index][:-1]
        index += 1
        numWords = processCase(case, letterPosToWords, wordlength)
        print "Case #%d: %d" % (i+1, numWords)


if __name__ == '__main__':
    main(sys.argv[1])
