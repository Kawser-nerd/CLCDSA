import math


max_rank, target_score = map(int, input().split())

problems = []
min_problems_count = 0
for i in range(max_rank):
	problems.append(list(map(int, input().split())))
	min_problems_count += problems[i][0]


def calc_score(answer_status):
	score = 0
	for i in range(max_rank):
		if answer_status[i] == '1':
			score += (problems[i][0] * 100 * (i + 1) + problems[i][1])
	return score


def calc_problems_count(answer_status):
	count = 0
	for i in range(max_rank):
		if answer_status[i] == '1':
			count += problems[i][0]
	return count


if __name__ == '__main__':
	for i in range(2 ** max_rank):
		is_clear = True
		answer_status = str(format(i, 'b')).zfill(max_rank)
		score = calc_score(answer_status)
		count = calc_problems_count(answer_status)
		if score < target_score:
			is_clear = False
			shortage_score = target_score - score
			min_counts = []
			for j in range(max_rank):
				if answer_status[j] == '0':
					needed_count = math.ceil(shortage_score / ((j + 1) * 100))
					if needed_count <= problems[j][0]:
						min_counts.append(needed_count)
						is_clear = True
			if is_clear:
				count += min(min_counts)
		if is_clear and count < min_problems_count:
			min_problems_count = count
	print(min_problems_count)