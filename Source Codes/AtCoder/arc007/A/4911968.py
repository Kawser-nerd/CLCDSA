# -*- coding: utf-8 -*-

import sys
import copy

input = sys.stdin.readline

# ---------------------------------------------------------


c = input().rstrip()
s = input().rstrip()

print(s.replace(c, ""))