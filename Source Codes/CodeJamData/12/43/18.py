#!/usr/bin/python

class Case():
	def __init__(self, number, properties):
		self.__dict__ = properties
		self.number = number
		self.answer = None
	
	def fix_input(self):
		# Fix input
		self.peaks = [int(p)-1 for p in self.peaks]
			
	def solve(self):
		# Solve case
		num_peaks = len(self.peaks)+1
		#peak_heights = range(0, num_peaks**2, num_peaks)
		peak_heights = [1]*num_peaks
		prev_highest = 0
		changing = True
		
		while changing:
			changing = False
			#print peak_heights
			for peak, highest in enumerate(self.peaks):
				if peak < prev_highest and highest > prev_highest:
					self.answer = "Impossible"
					return
			
				prev_highest = highest

				gradient = (peak_heights[highest] - peak_heights[peak])/(highest - peak)
				for p in xrange(peak+1, len(peak_heights)):
					if p == highest: continue
					too_high = (peak_heights[peak] + gradient*(p-peak))
					if peak_heights[p] >= too_high:
						changing = True
						if p > highest:
							g = (peak_heights[highest] - peak_heights[p])/(highest - p)
							peak_heights[peak] -= g*(highest-peak)+1
						else:
							peak_heights[p] = too_high - 1
		
		min_peak = min(peak_heights)
		if min_peak <= 0:
			peak_heights = [1+p-min_peak for p in peak_heights]
		self.answer = " ".join(map(str, peak_heights))
	
	def __str__(self):
		return "Case #%d: %s" % (self.number, self.answer)

class CaseParser():
	def __init__(self, infile, parameters):
		self.parameters = parameters

		self.infile = infile
		self.num_cases = None
	
	def cases(self):
		# Get the number of cases
		self.num_cases = int(self.infile.readline())

		for c in xrange(self.num_cases):
			# The properties for this case...
			props = {}
			for p in self.parameters:
				props[p] = self.infile.readline()
				if p == "peaks":
					props["peaks"] = self.infile.readline().split()
		
			yield Case(c+1, props)


if __name__ == "__main__":
	try:
		import sys
		infile_path = sys.argv[1]
	except IndexError:
		infile_path = "infile_path"
	infile = open(infile_path)
	
	params = ["peaks"]
	
	cp = CaseParser(infile, params)

	for case in cp.cases():
		case.fix_input()
		case.solve()
		print case
