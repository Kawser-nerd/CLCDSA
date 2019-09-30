package r2_2013;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("B.out"));

		for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			int n = in.nextInt();
			long p = in.nextLong();
			// guarantee
			{
				long lo = 0, hi = (1L << n)-1;
				while (lo < hi) {
					long md = (lo + hi + 1)/2;
					long lowest = lowest(n, md);
					//System.err.println(md + " " + lowest);
					if (lowest > p-1) hi = md-1;
					else lo = md;
				}
				out.print(lo);
			}
			{
				long lo = 0, hi = (1L << n)-1;
				while (lo < hi) {
					long md = (lo + hi + 1)/2;
					long highest = highest(n, md);
					//System.err.println(md + " " + highest);
					if (highest <= p-1) lo = md;
					else hi = md-1;
				}
				out.print(" " + lo);
			}
			out.println();
		}
		
		out.flush();
	}

	static long lowest(int r, long p) {
		if (r == 0) return 0;
		if (p == 0) return 0;
		return lowest(r-1, (p-1)/2) + (1L << (r-1));
	}
	
	static long highest(int r, long p) {
		if (r == 0) return 0;
		if (p+1 == (1L << r)) return (1L << r)-1;
		return highest(r-1, (1L << (r-1))-1-((1L << r)-1-p-1)/2);
	}
}
