'''
Created on May 23, 2010

@author: Mickalot

Problem

Now that you have won Code Jam and been hired Google as a software
engineer, you have been assigned to work on their wildly popular
programming contest website.

Google is expecting a lot of participants (P) in Code Jam next year,
and they want to make sure that the site can support that many
people at the same time. During Code Jam 2010 you learned that the
site could support at least L people at a time without any errors, 
but you also know that the site can't yet support P people.

To determine how many more machines you'll need, you want to know
within a factor of C how many people the site can support. This 
means that there is an integer a such that you know the site can 
support a people, but you know the site can't support a * C people.

You can run a series of load tests, each of which will determine
whether the site can support at least X people for some integer
value of X that you choose. If you pick an optimal strategy, choosing
what tests to run based on the results of previous tests, how many
load tests do you need in the worst case?

Input

The first line of the input gives the number of test cases, T.
T lines follow, each of which contains space-separated integers
L, P and C in that order.

Output

For each test case, output one line containing "Case #x: y", where
x is the case number (starting from 1) and y is the number of load
tests you need to run in the worst case before knowing within a 
factor of C how many people the site can support.
'''


def SolveCase(case_index, f):
	L, P, C = map(int, f.readline().split())
	#print "Case #%d: %d %d %d" % (case_index, L, P, C)
	count = 0
	lower = L
	while lower*C < P:
		count += 1
		lower = lower*C
	num_tests = 0
	while count > 0:
		count = int(count / 2)
		num_tests += 1
	print "Case #%d: %d" % (case_index, num_tests)


def Solve(f):
	num_cases = int(f.readline())
	for case_index in xrange(1, num_cases + 1):
		SolveCase(case_index, f)


if __name__ == '__main__':
	#Solve(open("B-test.in"))
	#Solve(open("B-small-attempt0.in"))
	Solve(open("B-large.in"))
	