import sys
import math
import itertools

for testcase in xrange(1, int(sys.stdin.readline())+1):

  num_tribes = int(sys.stdin.readline())

  wall_heights = {}
  days_of_attacks = []
  attacking_tribes = {}
  tribe_infos = []
  for index in range(num_tribes):
  	first_attack, num_attacks, first_west, first_east, first_strengh, days_between, east_between, strength_between = [int(w) for w in sys.stdin.readline().split()]
  	for attack_day in range(first_attack, first_attack+days_between*num_attacks, days_between):
  		if attack_day in attacking_tribes:
  			attacking_tribes[attack_day].append(index)
  		else:
  			attacking_tribes[attack_day] = [index]
  		days_of_attacks.append(attack_day)
  	tribe_infos.append([first_attack, num_attacks, first_west, first_east, first_strengh, days_between, east_between, strength_between])

  days_of_attacks.sort()
  successful_attacks = 0

  #print days_of_attacks
  for attack_day in days_of_attacks:
  	new_heights = {}
  	for tribe_index in attacking_tribes[attack_day]:
  		#print 'tribe: ' + str(tribe_index)
  		#print 'day: ' + str(attack_day)
  		success = 0
  		tribe_info = tribe_infos[tribe_index]
  		first_attack = tribe_info[0]
  		num_attacks = tribe_info[1]
  		first_west = tribe_info[2]*2
  		first_east = tribe_info[3]*2
  		first_strengh = tribe_info[4]
  		days_between = tribe_info[5]
  		east_between = tribe_info[6]*2
  		strength_between = tribe_info[7]
  		attack_number = (attack_day-first_attack)/days_between
  		attack_strength = first_strengh+attack_number*strength_between

  		#print 'strength: ' + str(attack_strength) 
  		if attack_strength <= 0:
  			continue
  		else:
  			west_point = first_west+attack_number*east_between
  			east_point = first_east + attack_number*east_between
  			for attack_point in range(west_point, east_point+1):
  				#print 'point :'+str(attack_point)
  				if attack_point in wall_heights:
  					if attack_strength > wall_heights[attack_point]:
  						success = 1
  					#else:
  						#print 'no good'
  				else:
  					success = 1
  				if attack_point in new_heights:
  					if attack_strength > new_heights[attack_point]:
  						new_heights[attack_point] = attack_strength
  				else:
  					new_heights[attack_point] = attack_strength
  		successful_attacks += success
  	for attack_point, attack_strength in new_heights.iteritems():
  		if attack_point in wall_heights:
  			if attack_strength > wall_heights[attack_point]:
  				wall_heights[attack_point] = attack_strength
  		else:
  			wall_heights[attack_point] = attack_strength

  print 'Case #%d: %d' % (testcase, successful_attacks)