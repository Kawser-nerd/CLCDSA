from __future__ import division
from functools32.functools32 import lru_cache
import sys
import itertools
import os
import re
import string
import math
import sys
import heapq
from collections import namedtuple, defaultdict, deque
from Tools import gcj
from Tools.gcj import printd
from bitstring import BitArray, BitStream
from copy import deepcopy
from simpleai.search import SearchProblem, astar
import random
import operator
#from Tools import primes
import networkx as nx
from networkx.algorithms import flow


def build_table(w, h, buildings):
    table = [[1 for i in range(w)] for j in range(h)]

    for range_cells in buildings:
        [x1, y1, x2, y2] = range_cells

        for i in xrange(y1, y2 + 1):
            for j in xrange(x1, x2 + 1):
                table[i][j] = 0
    return table

def get_out_name(i, j):
    e_name = "%d_%d" % (i, j)
    return e_name + "_out"

def build_graph(w, h, table):
    g_w = nx.DiGraph()

    g_w.add_node("source")
    g_w.add_node("target")

    for i in xrange(h):
        for j in xrange(w):
            g_w.add_node("%d_%d" % (i, j))
            g_w.add_node("%d_%d_out" % (i, j))

    for i in xrange(h):
        for j in xrange(w):
            e_name = "%d_%d" % (i, j)
            e_out_name = get_out_name(i, j)
            g_w.add_edge(e_name, e_out_name, {'capacity': table[i][j]})

            #up
            if i > 0:
                out2 = get_out_name(i - 1, j)
                g_w.add_edge(out2, e_name, {'capacity': 1})

            #left
            if j > 0:
                out2 = get_out_name(i, j - 1)
                g_w.add_edge(out2, e_name, {'capacity': 1})

            #right
            if j < w - 1:
                out2 = get_out_name(i, j + 1)
                g_w.add_edge(out2, e_name, {'capacity': 1})

            #down
            if i < h - 1:
                out2 = get_out_name(i + 1, j)
                g_w.add_edge(out2, e_name, {'capacity': 1})

    for j in xrange(w):
        e_name = "%d_%d" % (0, j)
        g_w.add_edge("source", e_name, {'capacity': 1})


        e_name = get_out_name(h-1, j)
        g_w.add_edge(e_name, "target", {'capacity': 1})


    for e in sorted(g_w.edges()):
        (u, v) = e
        data = g_w.get_edge_data(u, v)
        printd(e, data)
    return g_w

def solver(w, h, b, buildings):
    table = build_table(w, h, buildings)
    graph = build_graph(w, h, table)
    return flow.max_flow(graph, "source", "target")

def reader(in_file):
    """
    @type in_file: gcj.FileWrapper
    """
    w, h, b = in_file.getInts()
    buildings = []
    for i in xrange(b):
        (x0, y0, x1, y1) = in_file.getInts()
        buildings.append([x0, y0, x1, y1])

    return {
        'w': w,
        'h': h,
        'b': b,
        'buildings': buildings,
    }


if __name__ == "__main__":
    ### GCJ module http://jamftw.blogspot.com.es/2012/05/python-code-jam-wrapper.html
    gcj.GCJ(reader, solver, os.getcwd(), "").run()
