#!/usr/bin/python3

'''

Google Code Jam 2013
Qualification Round
Problem C - Fair and Square

Notes:
	* counting fair & square numbers in an interval
	* it's obvious from the special datasets that there are a few basic strategies we are expected to use, possibly with varying strengths and weaknesses
	* if we can figure out both before doing either problem, we could just add a check on the problem sizes at the outside, and choose the appropriate version of the code based on that
		* this would allow us to have a single program capable of handling all datasets
	* presumably we are to share calculations between cases, in order to get the best result with a large number of cases (large dataset 1)?
		* otherwise they would simply have made the number of cases the same and adjusted the problem size, and that would imply one solution was equal to or better than the other, and negate the need for the additional dataset
	* or maybe they just want to give people the opportunity to solve a large dataset, having only had either insight x or insight y, but if you have both, you can do both with the one program?
	
	* checking a single number for being fair & square is O(1) (if we assume number length in digits is limited), but iterating over the entire range provided and doing that check is still too slow (for the large datasets)
		* okay, checking a 100-digit number for fairness is actually 100 steps, and checking it for square-of-fairness is probably worse, since you're clearly not going to be using platform-native integers
	* but for once, let's do the small dataset first, with the intention to rewrite after solving it
	
	* it will be beneficial to determine the square roots of the range endpoints, and count through those, only checking the squares if the square root was found to be fair already
	* to ensure we still have the range correct, we should either:
		* round up for the lower bound and down for the upper bound, when determining the square-root range
			* this way seems better to me
		* or perform a range check on the resulting squared number, after finding it
	
	* so this simple solution works for the small dataset
	* will it work for the first large dataset?
	* sqrt(10**14) == 10**7 = 10 million
	* 10**7 * 10000 = 10**11 = 100 thousand million
		* that's clearly too large to iterate over
	* also, for the moment I'm just trusting that python will do something useful and reasonably fast with numbers outside the native integer range
		* I think my python is likely 64-bit, so that range would be 2**64 which is about 10**18 (wow, didn't realise it was that big)
		* guess we won't have to worry about non-native integers until we try for the large dataset 2
	* so to avoid that 10**11 iterations, we'll have to share data between cases
	* but... the most obvious method of precalculation won't really help reduce the number of iterations:
		* precalculate whether each number is fair and square or not, for every number in the biggest possible range
		* problem is, we still have to perform the same number of iterations, only we just check the array and increment, instead of performing squaring operations etc.
		* we could break it down somehow, but we don't know where the intervals will begin and end in the range, so how do we know where to break?
		* we could perhaps prepare aggregate values for halves, quarters, etc. of the max range, and somehow sum them to solve each case, but we'd have to store all those values and... well, it's getting complicated now
	* so... if our range is 10**7 (because we work in square roots all the time)...
		* we'll call 10**7 "n" for now
		* to store all the halves etc., would require log(n) arrays
		* the arrays would be size n/2, n/4, etc... up to n/n
		* the overall storage cells required, including the n-item array, would be no greater than 2n (reminds me of my google phone interview a couple of weeks ago)
		* to add up the values, you would first add the beginning and end items, if necessary (ie. if the beginning/end was on an odd boundary)
		* then you would switch to the next array (the halves) and do the same for the rounded beginning and end
		* then so on until you hit the final array of a single item, which would only be added if the entire range was covered
		* so you get your sum in log(n) steps
		* which is... about 24 steps?
			* which comes to 24 * 10000 = 240000 iterations overall
		* having to deal with a range that isn't a power of 2 is scaring me... but why not make it a power of 2 by extending the upper limit?
			* perhaps we could even skip calculating the elements we know won't be used?
	* things left to work out:
		* how do we organise the array elements
			* the elements will be stored in a 2n-size array (10**8 elements I guess)
			* we calculate the n individual elements in the outer array first
			* then we add the full size of that array to get the offset of the n/2 elements following
			* and so on
			* for both the calculation and the use of the data, we should be able to proceed from the large array to the smaller arrays
		* is there an easier way that is just as good, which I've ignored because I'm too focused on this direct approach to avoiding 10**7 iterations per case?
	* it's reasonably clear this will work, so I'll go ahead with it and worry about better solutions when I try the large dataset 2
	* thinking of a possibly-simpler way to organise the same rough calculation strategy:
		* perhaps use recursion and memoisation
		* we would have a function like count_range(lower, upper)
		* it would only ever be called with lower/upper bounds that fit into a specific power-of-2 grid
		* another function would be designed to take ranges that don't fit such a grid, and break it down into up to 2 calls that do and 1 call that doesn't necessarily (fit a power-of-2 grid)
		* but I'd rather try the non-recursive way for now
	
	* finer details:
		* we need to cover a range of 10**7 numbers
		* we'll require an array of size 2**(ceil(log(10**7, 2)))
		* multiplied by 2, to accommodate the half-size, quarter-size arrays etc.
		* so that's 2**25
	
	* in the end it got very confusing, but I managed to get things back under control by drawing a diagram to help work out the correct indexes into the counts table, and also by switching to a python-style interval where the closing value isn't actually included in the described interval
		* I think my resulting solution was correct
	
	* so now on to the large dataset 2?
	* I have the feeling a solution to this dataset will require some tricky insight
	* and once you have that insight, I suspect the solution won't be as complicated as the one I just did
	* probably the previous technique wouldn't be combined with this new one, because the previous one was based on calculating and summing individual values - I suspect a solution to large dataset 2 would avoid that altogether
	
	* the numbers are very big, up to 100 decimal digits long
	* treating them as strings, checking if a number is fair is quite easy
	* what about squaring and square root? can we somehow avoid that completely?
	* if we take the square root, the numbers go up to 10**50
	* our native ints only go to about 10**18... but who's to say we can't do this with non-native ints (ie. whatever python can do for us)?
	* we should worry first about the problem size in terms of iterations --- what if we were to apply our previous solution to this problem size, ignoring int representation issues for now?
	* the counts array would contain 10**51 elements, and take roughly that many iterations to produce
	* 51 - 24 = 27, and 2**27 = umm... a very large number... so the 37 seconds it took to prepare for large dataset 1 would be multiplied by 2**27, making waaay too much preparation time
	* so that solution is out of the question
	
	* this is not going to help me, but I realised numbers ending in 0 cannot be fair, because the calculation considers there to be no leading zeroes
	* for the large numbers, we may be using more techniques based on operating on the digits, instead of a single "integer" in our language
		* this may force us to subdivide sets of calculations based on the number of digits
		* ie. if the beginning of the range has less digits than the end, we may have to process the range in subranges with a fixed number of digits each
		* but these are all vague ideas that aren't really helping me to find the clever insight I need
	* what can we work out about the digits of a square, compared with the digits of the original square root?
	* more to the point, about the digits of a square of a palindrome..., since we won't bother squaring anything that isn't a palindrome
	* if we break down the multiplication, it can be a sum of simpler multiplications, each involving a single digit
	* when the 2 factors are the same, what special properties may arise regarding palindromes?
	* be careful to test any ideas against both even and odd-length numbers
		
		0123210**2
		
		= 0123210 * 0123210
		
		= 0123210         * 0
		+  0123210        * 1
		+   0123210       * 2
		+    0123210      * 3
		+     0123210     * 2
		+      0123210    * 1
		+       0123210   * 0
	
	* if this diagram amounts to anything, I'll have to draw another with even digits, to make sure the same conclusions still hold
	* it kinda gets difficult to draw conclusions when you start having to think about carrying digits into the next position during the multiplication and addition
		* and note that my digits here are merely placeholders - 0 is not actually 0 - more like an abbreviation for d[0]
	
	* but if we ignore carry for a bit...
		* the first digit is 0 * 0, the last is 0 * 0
		* the second is 1 * 0 + 0 * 1, the second last is 0 * 1 + 1 * 0
		* and so on...
		* so, if there's no carry, the square of a palindrome will itself be a palindrome
		* what about with carry?
		* well... how about I just test by experiment...
			* remove the fair() test for the squared number, and see if the results are the same for the datasets I've already processed
		* okay, I added a check for this in the fairsquare_inverted function, and quickly found a counterexample: 4**2 == 16, which is not fair
	
	* doing a bit of googling, I found this:
		All palindromic square numbers can only end with digit 1, 4, 5, 6 or 9.
		There exist no palindromic squares of length  2, 4, 8, 10, 14, 18, 20, 24, 30, 38, 40.
	* note that in our case, we're interested in palindromic squares with palindromic square roots only
	* I'm getting the impression that palindromic squares of these lengths are kind-of like prime numbers - something that is searched for and published when found, and not something you hack up an algorithm to find in a couple of hours
	* based on that "insight", I'm going to skip this problem for now and maybe return after having an attempt at problem d
	* okay, skipping the problem for now
	
	* I've now done all the other problems (fingers crossed that they're all correct), so it's just this one left
	* this could make the difference between a perfect score and a non-perfect score
	* and even if it took longer than most people would be willing to spend on the qualification round (after they already qualified), it serves as a showcase of my dedication
	* a perfect score in the qualification round actually means something in the competition lately, since they're making sure to put in some hard problems along with the easy ones
	* so... back to squares and palindromes...
	
	* maybe, if we can safely make a key assumption, we can manage this...
		* any palindromic number which overflows as part of the multiplication (ie. the squaring operation), will not have a palindromic square
		* but I'm not really all that sure it's correct
		* I'm sure that any palindromic number which doesn't overflow *will* have a palindromic square (as demonstrated by my above diagram)
		* the overflow always affects the digits to the left, not the digits to the "inside" or "outside", so it won't be properly reflected and breaks the palindrome
			* my only concern is that the number of digits could increase as a result of the overflow, and somehow the end result could be palindromic again (by rare chance), despite the asymmetry introduced by the overflow
				* but I'm willing to entertain the possibility that this is provably impossible, and therefore my desired assumption could hold in reality
	
	* so if we assume that overflow always kills a palindromic square, how can we use that assumption for the large dataset?
		* I guess the solution has to be hinged on countable ranges
			* we need to process ranges (I should say subsets, more generally, to avoid suggesting a linear range of consecutive integers) of numbers rather than individual numbers, because there are too man individual numbers to be processed
			* they have to be countable, because we have to be able to sum the amount of numbers in each range in order to determine the total amount of numbers overall
				* by countable, I mean we need a way to determine the number of matching values in the range, without iterating over every value
			* and the full set of ranges used has to be mutually exclusive and together have to cover the overall range we are interested in
		* can we break them down first by number of digits?
			* 
	
	* so the problem would then break down to finding the number of palindromes in the prescribed interval, which don't overflow when squared
	
	* oh shit I'm an idiot!:
		* it's not that hard!
		* we just need to produce a complete palindrome generator, instead of using a palindrome checker!
		* we take the range (in square root space)
		* we use our system (some yet-to-be-specified algorithm) to enumerate all the palindromes in the range
		* and for each one, we square it and check if the square is a palindrome
		* problems:
			* need to work out how to square a massive 100-decimal-digit number (but python might just do it for us, no questions asked - okay so long as we don't have to do too many of them)
			* wait... there's approx. 10**50 100-digit palindromes --- way too much still --- our limit would be approx. 10**8
	
	* estimate of the number of palindromes in a given range:
		* palindromes of exactly 100 digits
			* 50 decisions
			* 9 * 10**49
		* palindromes of from 1 to 100 digits:
			* it's definitely less than 10**50 * 100
			* I think it can be considered about 10**50 * 100
			* ie. 10**52
			* more precisely: 10**50 + 10**50 + 10**49 + 10**49 + 10**48 + 10**48 + ... + 10**1 + 10**1
			* we're not counting 0 here
			* and we're not considering that the first/last digit only has 9 options, not 10
	* to generate a sequence of palindromes in a given range:
		* pretty easy:
			iterate over the number of digits, from small to large
			for digits in range(mindigits, maxdigits+1):
				half = math.ceil(digits / 2)
				for left in range(10**(half-1), 10**half):		# this is (10**half)-1+1, if you like
					odd = digits % 2 == 1
					right = reversed(left[:-1] if odd else left)
					palindrome = str(left) + str(right)
		* for an initial attempt, just eliminate early and late values which are smaller than or greater than the overall range being covered?
	
	* I'm thinking of going with that assumption I mentioned above
	* the enumeration of the palindromes alone isn't enough to....
		* so I just need a way to combine the palindrome enumeration with the checking if the square is palindromic
	
	* wait.... I forgot that 10**100 is the range in squared space, not square-root space
	* so... that's 10**50 in square root space ((10**50)**2 == 10**100)
	* and then enumerating the palindromes within that range cuts it down again to 10**25
	* note that this is still significantly bigger than 2**64
	* and it's still significantly bigger than we want to iterate over
	* so we still need to combine the "square is a palindrome" check in as part of the enumeration
	
	* I suppose I can test my assumption by running my completed program on the large dataset we already have, and on the small dataset also --- that should be reasonable evidence whether it works or not
	
	* combining the square check into the enumeration:
		* we need to consider the diamond diagram above
			* I guess it's more of a rhombus, really
				* in fact I believe it is exactly a rhombus...
				* or at least a kind of manhattan rhombus...
				* although not really since the sides are 2 times the base, when measured in manhattan distance
			* how do we determine if some digit will overflow?
			* there is at least 1 column (the middle) where every digit is added together
				* beware that odd and even palindromes may work differently here...
				* testing:
					121    1221
					 121    1221
					  121    1221
					          1221
				* hmm.. they seem to be closer than I thought
			* but the digits are also multiplied by something... ah... by themselves in that middle column, at least
			* so one thing we could do is determine if the sum of the squares of all the digits is more than 10
			* but what if it's possible to overflow in a non-center digit, while not overflowing in the center digit?
			* I'm almost feeling like just assuming that if any digit overflows, the center one will
				* roughly, something about the biggest overall value being obtained, when grouping pairs and multiplying, by pairing the largest values with the largest values, and leaving the smallest to be paired with the smallest
				* clearly if some digit overflows, and the center digit is guaranteed to be at least as large as any other digit, then the center digit will overflow also
			* so let's then conclude that if the sum of the squares of all the original digits is greater than 9, the resulting squared number is not a palindrome
			* this means that ....
			* darn... I just had a look at a web site which lists some palindromic squares with a large number of digits, and I can see an example with digits the squares of which sum to 13
				* 10002000300020001
				* sqrt is 
			* so my assumption is wrong
			* I note the numbers do have a large number of zeroes, though
			* no wait!... the palindromic square has digits that when squared, sum to more than 10
			* but the square root is 100010001, which does not
			* so perhaps my assumption is true?
			* I checked out a couple more examples, and I'm ready to start believing my assumption again
	
	* for a second I thought I found a counterexample on that page again
		* 306930693**2 = 94206450305460249
		* but then I realised the page lists palindromes which are squares, not palindromes which are squares of palindromes
		* notice that the base number is not a palindrome
		* a lot of the numbers on the page have palindromic bases, but I think that's because the easiest way to find palindromic squares is to start with a palindromic base (with digits which when squared, sum to less than 10, I suppose)
	
	* I just discovered that python isn't going to magically save me from big numbers, at least not without some investigation first:
		>>> int(math.sqrt(2398423948724987423987439872349872349782439872439**2))
		                  2398423948724987283974433313333418468590665859072
	* a little research turned up the following, regarding big numbers:
		* python3 is supposed to use them by default
		* but that may not apply to floating point numbers
		* decimal is the floating-point equivalent to long (python's arbitrary-precision integer type)
		* there's something (a non-core module) called gmpy which I don't think I should look into right now, but it's related to big numbers
		* but... maybe my best technique to handle the big numbers would be to not handle them?
			* I just do the sum of squares of the digits thing, but don't actually square the numbers (of course)
			* since I'm not squaring the big numbers I don't need squaring operations in python to be accurate
				* note that in my python3 tests, both x**2 and math.sqrt(x) showed inaccuracy with large integers
				* oh wait, x**2 is accurate with integers
				* it was tricky to test, since the only way I knew was to do a math.sqrt, but that operation converts to float and loses precision
				* I thought the precision might have been lost in the original x**2 and tried converting to decimal ("Decimal(x)") first, but still got severe lack of precision
				* eventually I discovered that integer division can be done with the // operator, and did this:
					>>> x = 239084720934872041397824097821487656561661354897623876
					>>> x**2 // x
					239084720934872041397824097821487656561661354897623876
				* int(x**2 / x) doesn't work, as the division returns a float with limited precision:
					>>> int(x**2 / x)
					239084720934872056704537322929088059444869287618019328
					>>> int(x**2 // x)
					239084720934872041397824097821487656561661354897623876
	
	* so how do we, during our enumeration, exclude numbers with digits whose squares sum to 10 or more?
		* well... if we generate the numbers digit-by digit, perhaps recursively, we just have to limit the choices of subsequent digits to those that will not violate this restriction
		* so... we first iterate over number of digits
		* then we iterate over the possible digit values (I'll worry about which digit later)
		* but we first determine a maximum value for the digit, as follows:
			* take the sum of the squares of the digits so far, including their mirror reflections
			* note that the center digit (if it exists --- ie. if it's an odd number of digits) doesn't have a mirror reflection
			* subtract the sum from 9
			* find the floor of the square root of the result
			* that's the maximum value the digit can take
		* after choosing the digit value, recurse to determine remaining digits
		* this will cut the number of items to iterate over to much more managable levels
		* hopefully it won't inadvertently filter out valid square palindromes due to being based on an incorrect assumption
	
	* how do we initially determine the square root of the range?
		* we need to accurately determine the floor or ceiling of the square root of a very large number
		* we could roughly determine the square root (perhaps using the floating point math.sqrt function), and then search for the precise integer square root using x**2
		* since we only have to perform this operation twice per test case, this should be acceptably fast
		* I googled and found some code for integer square root functions, but I don't feel I have a lot of time to evaluate and select the best one
		* people suggest that it's very easy to get a bit wrong
		* here are some I'm considering:
			* http://code.activestate.com/recipes/577821-integer-square-root-function/
			* http://stackoverflow.com/questions/1623375/writing-your-own-square-root-function
				* considering the answer by Fredrik Johansson
			* oh, I see the first is python code based on the algorithm from the second URL
			* I'll take the python --- the guy sounds like he knows what he's talking about... I hope
		* at least I can test with the previous datasets, although they don't involve huge numbers
	
	* I just realised the numbers involved, after filtering down to the final palindromic squares we have to count, are so small that we may be able to store a list of them
		* for example, the output from the small dataset (numbers up to 10**14) never seem to go above 50, from a quick glance, despite the apparently-massive ranges in the input
		* this leads to a new technique...
	
	* we should calculate all fairsquares in advance:
		* we should calculate all fairsquares in the range from 1 to 10**100 (or rather, the square root of all those fairsquares, which would be in the range of 1 to 10**50) in advance
		* we store them all in a list, in order
		* then we iterate over the list and count the elements that are within the range specified for each case
		* nice and simple
		* avoids tricky issues adjusting the enumeration to work with specific ranges
	
	* for some reason I'm finding this a little tricky...:
		* when enumerating fairsquares, we want them in order
		* that means incrementing the least significant digit (of the "left" half) first
		* which means the least significant digit is adjusted on the *innermost* loop iteration, not the outermost
		* but if we do it this way (with recursion and explicit loops), we won't know the limits for the most significant digits until....
		* hmm... actually, the limits would apply to the least significant digits first, meaning the most significant would change first
		* this would get the numbers out of order
		* but we could always sort them afterwards, if this is too difficult to work around
		* in fact, there's no need to even sort them right now, so long as I'm iterating over all of them and just doing simple filtering
		* but I think I'll try to use a method based on an "increment" operation, instead, for now
		* might be a little less efficient due to the use of squaresum too frequently, but we'll see how we go --- we can fix it later if it's too slow
		* something like: if digit > 9 or squaresum() > 9: ...
	
	* I've defined a function squaresum() with no args...
		* there's 2 ways to use it:
			1. set a digit you're interested in to 0, run squaresum, and use the result to calculate the limit for that digit
			2. simply calculate the squaresum for the entire number (ie. don't set anything to 0 first)

'''

import sys
import time
import math

timeit = 1
debugv = 0

fairsquares = []
def prepare():
	for size in range(1,51):
		odd = (size % 2) == 1
		left_size = int(math.ceil(size / 2)) # includes the middle
		left = [1] + [0] * (left_size-1)
		
		def squaresum():
			return sum([x**2 * (1 if (odd and i == (left_size-1)) else 2) for i, x in enumerate(left)])
		
		def increment():
			digit = len(left)-1
			while 1:
				if digit < 0:
					return True # signal overflow
				left[digit] += 1
				# <<< warning: this implementation may make too many calls to squaresum, severely impacting efficiency (but we'll see how we go)
				if (left[digit] > 9) or (squaresum() > 9):
					left[digit] = 0
					digit -= 1
				else:
					return False # increment without overflow
		
		def emit_palindrome():
			right = list(reversed(left[:-1] if odd else left))
			palindrome = ''.join([str(d) for d in left + right])
			fairsquares.append(int(palindrome))
			# debug("found fairsquare {}\n".format(palindrome))
		
		while True:
			emit_palindrome()
			overflow = increment()
			if overflow:
				break
		sys.stderr.write("At {} digits: Found {} fairsquares so far.\n".format(size, len(fairsquares)))

def check():
	for n in fairsquares:
		if not fairsquare_inverted(n):
			raise Exception("{} is not an inverted fairsquare: ( {} )**2 = {}".format(str(n), str(n), str(n**2)))

def main():
	prepare()
	sys.stderr.write("Completed preparation in {} seconds.\n".format(time.clock() - startTime))
	sys.stderr.write("Found {} fairsquares.\n".format(len(fairsquares)))
	if 1:
		check()
	sys.stderr.write("Checked {} fairsquares - all are genuine fairsquares.\n".format(len(fairsquares)))
	T = int(sys.stdin.readline())
	for case in range(1,T+1):
		doCase(case)

def fair(n):
	digits = str(n)
	for i in range(round(len(digits) / 2)):
		if digits[i] != digits[len(digits)-1-i]:
			return False
	return True

def fairsquare_inverted(n):
	if not fair(n):
		return False
	
	square = n**2
	
	return fair(square)

def doCase(case):
	A, B = [int(n) for n in sys.stdin.readline().split()]
	
	# the range of square roots to check goes from start, up to but not including end
	start = isqrt_ceil(A)
	end = isqrt_floor(B) + 1
	
	# we could potentially use binary search here to find the endpoints, and then just find the difference between the endpoint indices
	# but I don't think we'll need to do that to get the required speed
	# (must make sure to test the speed with 1000 test cases)
	
	# result = len([n for n in fairsquares if start <= n < end])
	result = 0
	for fairsquare in fairsquares:
		if start <= fairsquare < end:
			result += 1
	
	debug("{}\n".format(result))
	sys.stdout.write("Case #{}: {}\n".format(case, result))

# isqrt from http://code.activestate.com/recipes/577821-integer-square-root-function/
def isqrt(x):
    if x < 0:
        raise ValueError('square root not defined for negative numbers')
    n = int(x)
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y

isqrt_floor = isqrt
def isqrt_ceil(x):
	floor = isqrt(x)
	if floor**2 == x:
		# exact integer square root: floor(sqrt(x)) == ceil(sqrt(x))
		return floor
	else:
		# non-integer square root
		return floor + 1

def debug(m):
	if debugv:
		sys.stderr.write(m)

if __name__ == '__main__':
	startTime = time.clock()
	main()
	if timeit:
		sys.stderr.write("Completed in {} seconds.\n".format(time.clock() - startTime))

