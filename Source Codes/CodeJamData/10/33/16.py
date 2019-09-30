'''
Created on May 23, 2010

@author: Darren
'''

def unhexify(hex_string):
    mapping = {
        '0': '0000',
        '1': '0001',
        '2': '0010',
        '3': '0011',
        '4': '0100',
        '5': '0101',
        '6': '0110',
        '7': '0111',
        '8': '1000',
        '9': '1001',
        'A': '1010',
        'B': '1011',
        'C': '1100',
        'D': '1101',
        'E': '1110',
        'F': '1111'}
    result = ''
    for i in xrange(len(hex_string)):
        result += mapping[hex_string[i]]
    return result

class Bark:
    def __init__(self, lines):
        self.lines = lines
        self.num_rows = len(lines)
        self.num_cols = len(lines[0])
        self.cell_to_size_hash = {}
        self.size_to_cells_hash = {}
        self.used_set = set()
        for row in xrange(self.num_rows):
            for col in xrange(self.num_cols):
                size = 1
                if self.cell_to_size_hash.has_key((row, col)):
                    size = self.cell_to_size_hash((row, col))
                stop = False
                while True:
                    if row+size >= self.num_rows or col+size >= self.num_cols:
                        break
                    
                    new_row = row+size
                    new_col = col+size
                    if self.lines[new_row-1][col] == self.lines[new_row][col]:
                        break
                    
                    for c in xrange(col, new_col):
                        if self.lines[new_row][c] == self.lines[new_row][c+1]:
                            stop = True
                            break
                    if stop: break
                    
                    for r in xrange(row, new_row):
                        if self.lines[r][new_col] == self.lines[r+1][new_col]:
                            stop = True
                            break
                    if stop: break
                    size += 1
                self.cell_to_size_hash[(row, col)] = size
                
                if not self.size_to_cells_hash.has_key(size):
                    self.size_to_cells_hash[size] = []
                self.size_to_cells_hash[size].append((row, col))

    def print_sizes(self):
        for size in sorted(self.size_to_cells_hash.keys(), reverse=True):
            print size, sorted(self.size_to_cells_hash[size])
    
    def process(self):
        result_hash = {}
        while True:
            # Assume all used cells are already out of size_to_cells and cells_to_size
            sizes = sorted(self.size_to_cells_hash.keys())
            if not sizes: break
            size = sizes[-1]
            cells = sorted(self.size_to_cells_hash[size])
            if not cells: break
            row, col = cells[0]
            
#            print "Testing size", size, "cell at", row, col
            size_accurate = True
            while True:
                botrow = row+size-1
                rightcol = col+size-1
            
                # verify this square is takeable
                if (row, rightcol) in self.used_set:
                    size -= 1
                    size_accurate = False
                    continue
                if (botrow, col) in self.used_set:
                    size -= 1
                    size_accurate = False
                    continue
                if (botrow, rightcol) in self.used_set:
                    size -= 1
                    size_accurate = False
                    continue
                break
#            print "Here"
            if not size_accurate:
                self.size_to_cells_hash[sizes[-1]].remove((row, col))
                if not self.size_to_cells_hash[sizes[-1]]:
                    del self.size_to_cells_hash[sizes[-1]]
                if size >= 1:
                    self.size_to_cells_hash[size].append((row, col))
                    self.cell_to_size_hash[(row, col)] = size
                else:
                    del self.cell_to_size_hash[(row, col)]
                continue
#            print "And here"
            
            # We're Good!
            # remove (row, col) from size_to_cells
            self.size_to_cells_hash[size].remove((row, col))
            if not self.size_to_cells_hash[size]:
                del self.size_to_cells_hash[size]
            
            #remove from cell_to_size
            del self.cell_to_size_hash[(row, col)]
            # mark used
            for r in xrange(row, botrow+1):
                for c in xrange(col, rightcol+1):                    
                    self.used_set.add((r, c))
                    if not self.cell_to_size_hash.has_key((r, c)): continue
                    origsize = self.cell_to_size_hash[(r, c)]
                    self.size_to_cells_hash[origsize].remove((r, c))
                    if not self.size_to_cells_hash[origsize]:
                        del self.size_to_cells_hash[origsize]
                    del self.cell_to_size_hash[(r, c)]
            
            # add to final result
            if not result_hash.has_key(size):
                result_hash[size] = []
            result_hash[size].append((row, col))
        return result_hash            

if __name__ == "__main__":
    f = open("C-small-attempt0.in", "r")
    fout = open("C-small-attempt0.out", "w")
    # T, the number of test cases in the input file
    T = int(f.readline())
    for i in xrange(T):
        M, N = [int(x) for x in f.readline().split()]
        lines = []
        for j in xrange(M):
            line = f.readline().strip()
            lines.append(unhexify(line))

#        for line in lines:
#            print line
        bark = Bark(lines)
#        bark.print_sizes()
        result_hash = bark.process()
        fout.write(''.join(('Case #', str(i+1), ': ', str(len(result_hash.keys())), '\n')))
        for size in sorted(result_hash.keys(), reverse=True):
            fout.write(''.join((str(size), ' ', str(len(result_hash[size])), '\n')))
#            print "  " + ", ".join([repr(x) for x in result_hash[size]])
#        print "Case", i+1
#        for line in lines:
#            print line
        
    fout.close()
    f.close()