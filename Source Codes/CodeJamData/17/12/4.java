import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

public class b {
	static final int STDIO = 0, SMALL = 1, LARGE = 2;
	static int inType = STDIO;
	static int outType = LARGE;

	public static void main(String[] args) throws IOException {
		Scanner in = getScanner();
		PrintWriter out = getPrintWriter();
		int maxT = in.nextInt();
		for (int curT = 1; curT <= maxT; curT++) {
			int n = in.nextInt(), p = in.nextInt();
			long[] rs = new long[n];
			for(int i=0;i<n;i++)
				rs[i] = in.nextInt();
			long[][] qs = new long[n][p];
			ArrayList<Event> es = new ArrayList<>();
			for(int i=0;i<n;i++) {
				for(int j=0;j<p;j++) {
					qs[i][j] = in.nextInt()*100;
					long a = 90*rs[i], b = 110*rs[i];
					long min = (qs[i][j]+b-1) / b;
					long max = qs[i][j] / a;
					min = Math.max(min, 1);
					if(min <= max) {
						es.add(new Event(min,i,1));
						es.add(new Event(max,i,-1));
					}
//					System.out.println(i + ": " + min + "-" + max + "(" + a + "," + b + ")");
				}
			}
			Collections.sort(es);
			int[] curCnts = new int[n];
			int[] usedCnts = new int[n];
			int ans = 0;
			for(Event e : es) {
//				System.out.println(e.time + " " + e.i + " " + e.delta);
				if(e.delta == -1) {
					if(usedCnts[e.i] > 0)
						usedCnts[e.i]--;
					else
						curCnts[e.i]--;
				} else {
					curCnts[e.i]++;
					boolean valid = true;
					for(int i=0;i<n;i++) {
						if(curCnts[i] == 0)
							valid = false;
					}
					if(valid) {
						for(int i=0;i<n;i++) {
							curCnts[i]--;
							usedCnts[i]++;
						}
						ans++;
//						System.out.println("make");
					}
				}
			}
			
			out.printf("Case #%d: ", curT);
			out.print(ans);
			//// OUTPUT
			
			out.println();
			if (inType != STDIO)
				System.out.println(curT + "/" + maxT);
		}

		out.close();
	}
	static class Event implements Comparable<Event>{
		long time, delta;
		int i;
		public Event(long time, int i, long delta) {
			this.time = time;
			this.i = i;
			this.delta = delta;
		}
		@Override
		public int compareTo(Event o) {
			if(time == o.time)
				return -Long.compare(delta, o.delta);
			return Long.compare(time, o.time);
		}
	}

	
	static final String PROBLEM_LETTER = "B";
	static Scanner getScanner() throws IOException {
		if (outType != STDIO)
			inType = outType;
		if (inType == SMALL)
			return new Scanner(new File(PROBLEM_LETTER + "-small-attempt0.in"));
		else if (inType == LARGE)
			return new Scanner(new File(PROBLEM_LETTER + "-large.in"));
		return new Scanner(System.in);
	}

	static PrintWriter getPrintWriter() throws IOException {
		if (outType == SMALL) {
			System.out.println("WRITING TO " + PROBLEM_LETTER +  "-SMALL");
			try {
				Thread.sleep(3000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			return new PrintWriter(new File(PROBLEM_LETTER + "-small.out"));
		} else if (outType == LARGE) {
			System.out.println("WRITING TO " + PROBLEM_LETTER + "-LARGE");
			try {
				Thread.sleep(3000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			return new PrintWriter(new File(PROBLEM_LETTER + "-large.out"));
		}
		return new PrintWriter(System.out);
	}
}
