import java.io.*;
import java.util.*;

public class Solution implements Runnable {

	private StringTokenizer st;
	private BufferedReader in;
	private PrintWriter out;
	
	static final String filename = "B-large";

	static int mod = 10009;
	
	static class Term {
		char[] ar;
		
		Term(char[] ar) {
			this.ar = ar;
		}
		
		public int hashCode() {
			return Arrays.hashCode(ar);
		}
		
		public boolean equals(Object obj) {
			Term t = (Term)obj;
			return Arrays.equals(ar, t.ar);
		}
		
		HashMap<Term, Integer> sub(int[] vals, int mul0) {
			HashMap<Term, Integer> ret = new HashMap<Term, Integer>();
			for (int mask = 0; mask < 1 << ar.length; ++mask) {
				int mul = mul0;
				char[] ar2 = new char[Integer.bitCount(mask)];
				for (int i = 0, j = 0; i < ar.length; ++i) {
					if ((mask & (1 << i)) == 0) {
						mul = (mul * vals[ar[i] - 'a']) % mod;
					} else {
						ar2[j++] = ar[i];
					}
				}
				if (mul == 0) {
					continue;
				}
				inc(ret, new Term(ar2), mul);
			}
			return ret;
		}
	}
	
	public void solve(int test) throws IOException {
		System.out.println("Case #" + test);
		out.print("Case #" + test + ": ");
		Term t0 = new Term(new char[0]);
		String str = next();
		int k = nextInt();
		HashMap<Term, Integer> poly = new HashMap<Term, Integer>();
		for (String s : str.split("\\+")) {
			inc(poly, new Term(s.toCharArray()), 1);
		}
		int wc = nextInt();
		String[] ws = new String[wc];
		for (int i = 0; i < wc; ++i) {
			ws[i] = next();
		}
		int[] val = new int[26];
		for (int it = 0; it < k; ++it) {
			HashMap<Term, Integer> newPoly = new HashMap<Term, Integer>();
			for (String s : ws) {
				Arrays.fill(val, 0);
				for (char t : s.toCharArray()) {
					val[t - 'a']++;
				}
				for (Term t : poly.keySet()) {
					addAll(newPoly, t.sub(val, poly.get(t)));
				}
			}
			poly = newPoly;
			out.print((poly.containsKey(t0) ? poly.get(t0) : 0) + " ");
		}
		out.println();
	}
	
	public static void inc(HashMap<Term, Integer> ret, Term term, int val) {
		if (ret.containsKey(term)) {
			ret.put(term, (ret.get(term) + val) % mod);
		} else {
			ret.put(term, val);
		}
	}
	
	public static void addAll(HashMap<Term, Integer> a, HashMap<Term, Integer> b) {
		for (Term t : b.keySet()) {
			inc(a, t, b.get(t));
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
