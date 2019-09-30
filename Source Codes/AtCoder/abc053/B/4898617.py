s = input()
pos = 0
while s[pos] != 'A':
    pos += 1

end = len(s)-1
while s[end] != 'Z':
    end -= 1

print(end - pos + 1)