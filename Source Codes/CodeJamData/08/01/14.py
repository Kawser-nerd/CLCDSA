#! /opt/local/bin/python
# -*- coding: utf8 -*-

def do_calc(num_engine, query):
    change = 0
    flags = [0] * num_engine

    for q in query:
        flags[q] = 1
        if flags.count(0) == 0:
            flags = [0] * num_engine
            flags[q] = 1
            change += 1

    return change


def main():
    for c in range(input()):
        dic_engine = {}
        query = []
        num_engine = input()

        for i in range(num_engine):
            tmp_str= raw_input()
            dic_engine[tmp_str] = i

        num_query = input()

        for i in range(num_query):
            str_query = raw_input()
            query.append(dic_engine[str_query])

        change = do_calc(num_engine,query)
 
        print 'Case #%d: %d' % ( c+1, change )

if __name__ == '__main__':
    main()
