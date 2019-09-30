""" Reads in a file and yields 1 line at a time """
def reader(f):
    f = open(f)
    for line in f:
        yield line.strip()
    f.close()

""" Writes a file in the format required """
def write(f, lst):
    for i in xrange(len(lst)):
        lst[i] = "Case #%s: %s" % (i + 1, lst[i])
    f = open(f,'w')
    f.write('\n'.join(lst))
    f.close()
