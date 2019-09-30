
file_in = open('a.in', 'r')
file_out = open('a.out', 'w')

n_case = int(file_in.readline())

class Word:
    def __init__(self, s):
        char = '0'
        self.chars = []
        self.counts = []
        for c in s:
            if c != char:
                self.chars.append(c)
                self.counts.append(1)
                char = c
            else:
                self.counts[-1] += 1

for i_case in range(n_case):
    # print i_case

    N = int(file_in.readline())
    words = []
    for i in range(N):
        words.append(Word(file_in.readline().strip()))


    chars = words[0].chars
    def check_equal():
        for word in words:
            if word.chars != chars:
                return False
        return True

    if not check_equal():
        file_out.write("Case #%d: %s\n" % (i_case + 1, "Fegla Won"))
        continue

    def median(arr):
        s = sorted(arr)
        return s[len(s)/2]
    def actions_needed(arr):
        count = 0
        med = median(arr)
        for a in arr:
            count += abs(med - a) 
        return count

    actions = 0 

    #print chars
    for i_char in range(len(chars)):
        arr = []
        for word in words:
            #print len(word.counts)
            arr.append(word.counts[i_char])
        actions += actions_needed(arr)

    file_out.write("Case #%d: %s\n" % (i_case + 1, str(actions)))

file_in.close()
file_out.close()
