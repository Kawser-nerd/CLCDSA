import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
//	static Scanner in; static int next() throws Exception {return in.nextInt();};
	static StreamTokenizer in; static int next() throws Exception {in.nextToken(); return (int) in.nval;};
//	static BufferedReader in;
	static PrintWriter out;
	static String NAME = "b";
	
	public static void main(String[] args) throws Exception {
//		in = new Scanner(new File(NAME + ".in"));
		in = new StreamTokenizer(new BufferedReader(new FileReader(new File(NAME + ".in"))));
//		in = new BufferedReader(new FileReader(new File(NAME + ".in")));
		out = new PrintWriter(new File(NAME + ".out"));
			
		int tests = next();
		
		for (int test = 1; test <= tests; test++) {
			int n = next();
			if (n == 0) {
				out.println("Case #" + test + ": 0");
				continue;
			}
			int m = 10005;
			int[] k = new int[m];
			for (int i = 0; i < n; i++) k[next()]++;
			int answ = 100000;
			int start = 0;
			int end = 0;
			while (true) {
				while (start < m && k[start] == 0) start++;
				if (start == m) break;
				end = start;
				while (k[end] != 0) end++;
				
				ArrayList<Integer> s = new ArrayList<Integer>();
				ArrayList<Integer> e = new ArrayList<Integer>();
				for (int i = start; i <= end; i++) {
					if (k[i] > k[i - 1]) for (int j = 0; j < k[i] - k[i - 1]; j++) s.add(i);
					if (k[i] < k[i - 1]) for (int j = 0; j < k[i - 1] - k[i]; j++) e.add(i);
				}
				for (int i = 0; i < s.size(); i++) answ = Math.min(answ, e.get(i) - s.get(i));
				start = end;
			}
			
			out.println("Case #" + test + ": " + answ);
			
		}
		
		out.close();
	}
	
}