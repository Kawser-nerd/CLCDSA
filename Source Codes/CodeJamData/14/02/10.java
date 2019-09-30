package con2014Q;

import java.io.*;
import java.util.*;

public class B {
	
	private static final String islarge = "-large";
	private static final String fileName = "results/con2014Q/"+B.class.getSimpleName().toLowerCase()+islarge;
	private static final String inputFileName = fileName + ".in";
	private static final String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	private void solve() {
		double C = Double.parseDouble(in.next()), 
				F = Double.parseDouble(in.next()), 
				X = Double.parseDouble(in.next());
		double best = X/2;
		double cur = 0;
		int a_farms = 0;
		while(cur < best){
			cur += C/(2+(a_farms*F)); // cost to buy next farm
			a_farms++;
			best = Math.min(best, cur+(X/(2+(a_farms*F))));
		}
		
		out.format("%.7f%n",best);
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		long start = System.currentTimeMillis();
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new B().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
		long stop = System.currentTimeMillis();
		System.out.println(stop-start+" ms");
	}
}
