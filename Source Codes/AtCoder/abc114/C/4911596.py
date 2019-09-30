n = int(input())
def counter(num1, num2):
	if num2 == "0":
		num21 = "3"
		num22 = "5"
		num23 = "7"
		return counter(num1, num21) + counter(num1, num22) + counter(num1, num23)
	elif int(num2) > num1:
		return 0
	else:
		result = 0
		num21 = "3" + num2
		num22 = "5" + num2
		num23 = "7" + num2
		if "3" in num21 and "5" in num21 and "7" in num21 and int(num21) <= num1:
			result += 1
		if "3" in num22 and "5" in num22 and "7" in num22 and int(num22) <= num1:
			result += 1
		if "3" in num23 and "5" in num23 and "7" in num23 and int(num23) <= num1:
			result += 1
		return counter(num1, num21) + counter(num1, num22) + counter(num1, num23) + result

print(counter(n, "0"))