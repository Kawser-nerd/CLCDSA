import java.io.IOException;

//Begun 8:45pm

public class ProblemC extends CodeJammer {

	@Override
	public void process() throws IOException {
		// TODO Auto-generated method stub
		long[] line1 = reader.readLongArray();
		long r = line1[0]; //number of runs
		long k = line1[1]; //capacity 
		int n = (int) line1[2]; //number of groups
		long[] g = reader.readLongArray(); //group sizes
		
		int depth = (int) (Math.log(r) / Math.log(2)) + 2; //how many rows to make... added 2, not 1 in case of round-off error, just to be safe.
		
		int[][] indexReached = new int[depth][n]; //If group j departs first, entry (i,j) tells the index of the first group to board after 2^i runs
		long[][] riders = new long[depth][n]; //If ("), tells the number of people to ride in the next 2^i runs
		//Make the cache at depth 0
		for (int i=0; i<n; i++) {
			long boarded = 0;
			int next = i;
			do {
				boarded += g[next];
				next++;
				if (next >= n) next -= n;
			} while (next != i && boarded+g[next]<=k); //stop if you wrap all the way around, or if the next group would push over the limit
			indexReached[0][i] = next;
			riders[0][i] = boarded;
		}
		
		//Go to further depths
		for (int d=1; d<depth; d++) {
			for (int i=0; i<n; i++) {
				int middleIndex = indexReached[d-1][i];
				indexReached[d][i] = indexReached[d-1][middleIndex];
				riders[d][i] = riders[d-1][i] + riders[d-1][middleIndex];
			}
		}
		
		//Now add up the riders.
		long ridesLeft = r;
		long total = 0;
		int nextIndex = 0;
		while (ridesLeft > 0) {
			long chunk = 1;
			int d = 0;
			while (2*chunk <= ridesLeft) { //taking the log by hand to avoid rounding error... silly, I know.
				chunk *= 2;
				d += 1;
			}
			
			ridesLeft -= chunk;
			total += riders[d][nextIndex];
			nextIndex = indexReached[d][nextIndex];
		}
		
		output(total);
		
	}
	
	public static void main(String[] args) {
		ProblemC p = new ProblemC();
		p.run(args);
	}

}
