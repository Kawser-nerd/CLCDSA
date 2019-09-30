import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	static final String filename = "A-large";

	static class Tree {
		double p;
		String split;
		Tree l, r;
		
		Tree(StringTokenizer st) {
			st.nextToken();
			p = Double.parseDouble(st.nextToken());
			String nt = st.nextToken();
			if (!nt.equals(")")) {
				split = nt;
				l = new Tree(st);
				r = new Tree(st);
				nt = st.nextToken();
			}
		}

		public double eval(HashSet<String> set) {
			if (split == null) {
				return p;
			}
			return p * (set.contains(split) ? l : r).eval(set);
		}
	}
	
	public void solve(int test) throws IOException {
		out.println("Case #" + test + ": ");
		int lines = nextInt();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < lines; ++i) {
			sb.append(in.readLine()).append(" ");
		}
		String s = sb.toString().replace("(", " ( ").replace(")", " ) ");
		StringTokenizer st = new StringTokenizer(s, " ");
		Tree t = new Tree(st);
		int n = nextInt();
		for (int i = 0; i < n; ++i) {
			next();
			int k = nextInt();
			HashSet<String> set = new HashSet<String>();
			for (int j = 0; j < k; ++j) {
				set.add(next());
			}
			out.println(t.eval(set));
		}
	}
	
	public void run() {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			out = new PrintWriter(filename + ".out");
			eat("");
			
			int tests = nextInt();
			for (int test = 0; test < tests; ++test) {
				solve(test + 1);
			}
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		} catch (OutOfMemoryError er) {
			List<int[]> x = new ArrayList<int[]>();
			while (true) {
				x.add(new int[100000]);
			}
		}
	}
	
	void eat(String s) {
		st = new StringTokenizer(s);
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Thread(new Solution()).start();
	}
	
}
