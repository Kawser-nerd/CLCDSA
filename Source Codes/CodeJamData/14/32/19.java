import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;


public class ProblemB {

	public static void main(String[] args) throws IOException {
		
		ProblemB solver = new ProblemB();
		solver.init();
		solver.solve();
	}
	
	void init() {
	}
	
	final static int MOD = 1000000007;
	
	private void solve() throws IOException {
		
		Reader in = new Reader(System.in);
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			int N = in.nextInt();
			List<String> tokens = new LinkedList<String>();
			for (int i = 0; i < N; i++) tokens.add(in.next());
			int[] both = new int[26];
			int[] left = new int[26];
			int[] right = new int[26];
			int[] g = new int[26];
			Arrays.fill(g, -1);
			int[] isInside = new int[26];
			//boolean impossible = false;
			
			for (String token : tokens) {
				char[] str = squezee(token.toCharArray());
				if (allTheSame(str)) both[token.charAt(0) - 'a']++;
				else {
					left[str[0] - 'a']++;
					right[str[str.length - 1] - 'a']++;
					g[str[0] - 'a'] = str[str.length - 1] - 'a';
					for (int i = 1; i < str.length - 1; i++) {
						if (str[i] != str[i-1]) isInside[str[i] - 'a']++;
					}
				}
			}
			
			long r = 0;
			if (!impossible(both,left,right,g,isInside)) {
				int components = 0;
				boolean[] used = new boolean[26];
				for (int i = 0; i < 26; i++) {
					if (left[i] == 1 && right[i] == 0) {
						go(i,g,used);
						components++;
					}
				}
				if(!impossible(left,right,used)) {
					r = 1;
					for (int b : both) {
						r *= fact(b);
						r = r % MOD;
					}
					for (int i = 0; i < 26; i++) {
						if (both[i] > 0 && left[i] == 0 && right[i] == 0) components++;
					}
					r *= fact(components);
					r = r % MOD;
				}
			}
			
			
			out.println("Case #" + t + ": " + r);
		}
		out.flush();
		out.close();
	}
	
	private char[] squezee(char[] str) {
		String s1 = "" + str[0];
		char last = str[0];
		for (int i = 1; i < str.length; i++) {
			if (str[i] != last) {
				s1 += str[i];
				last = str[i];
			}
		}
		return s1.toCharArray();
	}

	private int fact(int n) {
		long r = 1;
		for (int k = 2; k <= n; k++) {
			r = (r * k) % MOD;
		}
		return (int)r;
	}

	private boolean impossible(int[] left, int[] right, boolean[] used) {
		for (int i = 0; i < 26; i++) {
			if (left[i] == 1 && right[i] == 1 && !used[i]) return true;
		}
		return false;
	}

	private void go(int i, int[] g, boolean[] used) {
		if (i == -1) return;
		used[i] = true;
		go(g[i], g, used);
	}

	private boolean impossible(int[] both, int[] left, int[] right,
			int[] g, int[] inside) {

		for (int i = 0; i < g.length; i++) {
			if (g[i] == i) return true;
			if (inside[i] >= 2) return true;
			if (inside[i] == 1) {
				if (both[i] > 0 || left[i] > 0 || right[i] > 0) return true;
			}
			if (left[i] >= 2 || right[i] >= 2) return true;
		}
		return false;
	}

	private boolean allTheSame(char[] str) {
		for (int i = 1; i < str.length; i++) {
			if (str[i] != str[i-1]) return false;
		}
		return true;
	}

	private static class Reader {
	    BufferedReader reader;
	    StringTokenizer tokenizer;

	    /** call this method to initialize reader for InputStream */
	    Reader(InputStream input) {
	        reader = new BufferedReader(
	                     new InputStreamReader(input) );
	        tokenizer = new StringTokenizer("");
	    }

	    public void skipLine() throws IOException {
			reader.readLine();
		}

		/** get next word */
	    public String next() throws IOException {
	        while ( ! tokenizer.hasMoreTokens() ) {
	            //TODO add check for eof if necessary
	            tokenizer = new StringTokenizer(
	                   reader.readLine() );
	        }
	        return tokenizer.nextToken();
	    }

	    public int nextInt() throws IOException {
	        return Integer.parseInt( next() );
	    }
	    
	    public double nextDouble() throws IOException {
	        return Double.parseDouble( next() );
	    }
	    
	    public long nextLong() throws IOException {
	    	return Long.parseLong(next());
	    }
	}
}
