import java.io.*;
import java.util.*;

public class Main {
//	static Scanner in; static int next() throws Exception {return in.nextInt();};
	static StreamTokenizer in; static int next() throws Exception {in.nextToken(); return (int) in.nval;}
	static PrintWriter out;
	static String NAME = "a";

	public static void main(String[] args) throws Exception {
//		in = new Scanner(new File(NAME + ".in"));
		out = new PrintWriter(new File(NAME + ".out"));
		in = new StreamTokenizer(new BufferedReader(new FileReader(new File(NAME + ".in"))));
		
		int tests = next();

		for (int test = 1; test <= tests; test++) {
		    int x = next();
		    int s = next();
		    int r = next();
		    double t = next();
			int n = next();
			int m = 101;
			int[] l = new int[m];
			l[0] = x;
			for (int i = 0; i < n; i++) {
				int b = next();
				int e = next();
				l[next()] += e - b;
				l[0] -= e - b;
			}

			double answ = 0;
			for (int i = 0; i < m; i++) {
				double tt = Math.min(t, (double)l[i]/(i + r));
				t -= tt;
				answ -= tt*(r - s)/(i + s);
			}
			for (int i = 0; i < m; i++) answ += (double)l[i]/(i + s);
			
			out.println("Case #" + test + ": " + answ);
		}

		
		out.close();
	}
}