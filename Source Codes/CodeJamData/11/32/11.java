import java.io.*;
import java.util.*;

public class Main {
	
	Scanner in;
	PrintWriter out;
	
	static final String problem = "B-large";
	
	static void asserT(boolean e) {
		if (!e) {
			throw new Error();
		}
	}
	
	static class Dist implements Comparable <Dist> {
		long prevValue;
		long currValue;
		
		Dist(long prevValue, long currValue) {
			this.prevValue = prevValue;
			this.currValue = currValue;
		}
		
		long win() {
			return prevValue - currValue;
		}
		
		int sign(long val) {
			if (val > 0) {
				return 1;
			} else if (val < 0) {
				return -1;
			} else {
				return 0;
			}
		}
		
		public int compareTo(Dist second) {
			return sign(second.win() - this.win()); 
		}
	}
	
	void solveOne() {
		int boostCount = in.nextInt();
		long timeToBuild = in.nextLong();
		int lastStarIdx = in.nextInt() - 1;
		int cycle = in.nextInt();
		
		long dist[] = new long[cycle];
		for (int i = 0; i < dist.length; i++) {
			dist[i] = in.nextInt();
		}
		
		long allDist[] = new long[lastStarIdx + 1];
		for (int i = 0; i < allDist.length; i++) {
			allDist[i] = dist[i % cycle];
		}
		
		int firstGoodIdx = lastStarIdx + 1;
		long sum = 0;
		for (int i = 0; i < allDist.length; i++) {
			if (sum * 2 + allDist[i] * 2 > timeToBuild) {
				firstGoodIdx = i;
				break;
			}
			sum = sum + allDist[i];
		}
		long timeBefore = sum * 2;
		if (firstGoodIdx == lastStarIdx + 1) {
			out.println(sum * 2);
			return;
		}
		Dist winTimes[] = new Dist[lastStarIdx + 1 - firstGoodIdx];
		
		
		for (int i = firstGoodIdx; i < allDist.length; i++) {
			if (i == firstGoodIdx) {
				long timeNext = (sum + allDist[i]) * 2;
				
				long way = (timeToBuild - sum * 2) / 2;
				long boosted = way * 2 + (timeNext - timeToBuild) / 2;
				
				winTimes[i-firstGoodIdx] = new Dist(allDist[i] * 2, boosted);
			} else {
				winTimes[i-firstGoodIdx] = new Dist(allDist[i] * 2, allDist[i]);
			}
			sum += allDist[i];
		}
		Arrays.sort(winTimes);
		long time = 0;
		for (int i = 0; i < winTimes.length; i++) {
			if (i < boostCount) {
				time += winTimes[i].currValue;
			} else {
				time += winTimes[i].prevValue;
			}
		}
		out.println(time + timeBefore);
	}
	
	void solve() {
		int nTests = in.nextInt();
		for (int i = 0; i < nTests; i++) {
			out.print("Case #"+(i+1)+": ");
			solveOne();
		}
	}
	
	void run() {
		try {
			in = new Scanner(new FileReader("C:\\roundC\\" + problem + ".in"));
			out = new PrintWriter(new FileWriter("C:\\roundC\\" + problem + ".out3"));
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
		}
		
		try {
			solve();
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
}