#!/usr/bin/env pypy

# Calculated in the naive way
SMALL_FAIRSQUARES = (0, 1, 4, 9, 121, 484, 10201, 12321, 14641, 10201, 40804, 44944, 40804, 1234321, 1002001, 4008004, 121242121, 123454321, 125686521, 121242121, 100020001, 400080004, 12345654321, 12102420121, 10000200001, 40000800004, 1232346432321, 1234567654321, 1232346432321, 1210024200121, 1000002000001, 4000008000004, 123456787654321, 123212464212321, 121000242000121, 100000020000001, 400000080000004, 12343456865434321, 12345678987654321, 12343456865434321, 12321024642012321, 12100002420000121, 10000000200000001, 40000000800000004, 1234323468643234321, 1232100246420012321, 1210000024200000121, 1000000002000000001, 4000000008000000004)

import sys
import itertools
from collections import defaultdict

def readline():
	s = raw_input().strip()
	while s == "":
		s = raw_input().strip()
	return s

def readvals():
	return map(int, readline().split())

def generate_palindromes_of_length(digits):
	if digits == 1:
		for i in range(0, 10):
			yield i
	elif digits == 2:
		for i in range(0, 10):
			yield i * 11
	elif digits > 2:
		rest = tuple(map(str, generate_palindromes_of_length(digits - 2)))
		rest = rest + ("0" * (digits - 2),)
		for c in "0123456789":
			for p in rest:
				yield int(c + p + c)

def is_palindrome(n):
	s = str(n)
	X = len(s) // 2
	return s[:X] == s[:-X-1:-1]

def generate_palindromes():
	digits = 1
	while True:
		for x in generate_palindromes_of_length(digits):
			if len(str(x)) == digits:
				yield x
		digits += 1

def generate_fairsquare(limit):
	for p in generate_palindromes():
		sq = p * p
		if sq > limit:
			break
		if is_palindrome(sq):
			yield sq

def should_discard(candidate):
	if candidate < 10 ** 10:
		return False
	digits = map(int, str(candidate))

	total = 0
	sq = 0
	for x in digits:
		sq = x*x
		total += sq*2
	total -= sq
	return total > 9


def smart_candidates():
	"""
	Generates a sorted sequence of possible beginnings of palindromes that
	can be squared to form fair square palindromes
	0 1 2 3 9 10 11 12 13 20 ....
	"""
	generated = [0]
	yield 0

	while 1:
		candidate = generated.pop(0)
		if should_discard(candidate):
			continue
		for i in range(10):
			x = candidate * 10 + i
			if should_discard(x):
				break
			if x == 0:
				continue
			n = len(str(x))
			reversed_x = int(str(x)[::-1])
			reversed_x_squared = reversed_x ** 2
			desired = str(reversed_x_squared)[:-n-1:-1]
			desired += "0" * (n - len(desired))


			# ignore around sqrt(10) for now....
			low = str(x*x)[:n]
			high = str((x+1)*(x+1))[:n]
			#print("{0}\t{1}\t{2}\tx={3}".format(low, high, desired, x))
			if low <= desired <= high or high < low:
				if low == desired:
					yield x
				generated.append(x)

def generate_fast_palindromes(limit):
	fairsquare = set()
	considered = []
	# Generate odd length palindrome candidates...
	for prefix in itertools.imap(str, smart_candidates()):
		considered.append(prefix)
		n = int(prefix + prefix[-2::-1])
		sq = n*n
		if sq > limit:
			break
		if is_palindrome(sq):
			#print("{0} gives {1}".format(prefix, sq))
			fairsquare.add(sq)

	for prefix in considered:
		n = int(prefix + prefix[::-1])
		sq = n*n
		if sq > limit:
			break
		if is_palindrome(sq):
			#print("{0} gives {1}".format(prefix, sq))
			fairsquare.add(sq)
	return tuple(sorted(fairsquare))


palindromes = generate_fast_palindromes(10**100)
sys.stderr.write("Done generating\n")



if __name__ == "__main__":
	# precompute palindromes

	def solve():
		low, high = readvals()
		return count_fair_square(high) - count_fair_square(low - 1)
	def count_fair_square(limit):
		"""
		Returns a count of how many fair squares are <= limit
		"""
		low, high = 0, len(palindromes) - 1
		while low <= high:
			mid = (low + high) // 2
			if palindromes[mid] <= limit:
				low = mid + 1
			else:
				high = mid - 1
		return high + 1


	N = int(readline())
	for i in range(N):
		sol = solve()
		print("Case #{0}: {1}".format(i+1, sol))
