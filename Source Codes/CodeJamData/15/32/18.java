import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
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
	
	int K;
	int S;
	int[] ks;
	char[] ls;
	
	private void solve() throws IOException {
		
		Reader in = new Reader(System.in);
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			K  = in.nextInt();
			int L = in.nextInt();
			S = in.nextInt();
			ks = initKs(in.next().toCharArray());
			ls = in.next().toCharArray();
			int LP = findBestSuffix(ls);
			
			int MAX = findMax(S, L, LP);
			
			double r = 0;
			if (possible(ks, ls)) {
				r = MAX - expected();
			}
			
			out.println("Case #" + t + ": " + r);
		}
		out.flush();
		out.close();
	}
	
	private double expected() {
		List<Character> alpha = new ArrayList<Character>();
		for (int i = 0; i < ks.length; i++) if (ks[i] > 0) alpha.add((char)('A' + i));
		char[] str = new char[S];
		return generate(0,alpha,str);
	}

	private double generate(int pos, List<Character> alpha, char[] str) {
		if (pos == str.length) return count(str, ls);
		else {
			double r = 0;
			for (char c : alpha) {
				str[pos] = c;
				r += generate(pos + 1, alpha, str) * 1.0 * ks[c - 'A'] / K;
			}
			return r;
		}
	}

	private int count(char[] str, char[] ls) {
		int r = 0;
		for (int start = 0; start + ls.length <= str.length; start++) 
			if (same(str, ls, start)) r++;
		return r;
	}

	private boolean same(char[] str, char[] ls, int start) {
		for (int i = 0; i < ls.length; i++) if (str[start + i] != ls[i]) return false;
		return true;
	}

	private boolean possible(int[] ks, char[] ls) {
		for(char c : ls) if (ks[c - 'A'] == 0) return false;
		return true;
	}

	private int findMax(int s, int l, int lP) {
		if (l <= s) {
			return 1 + findMax(s - lP, l, lP);
		} else {
			return 0;
		}
	}

	private int findBestSuffix(char[] ls) {
		int lp = 1;
		for (; lp < ls.length; lp++) {
			if (equalsString(ls, lp)) break;
		}
		return lp;
	}

	private boolean equalsString(char[] ls, int lp) {
		for (int i = 0; lp + i < ls.length; i++) {
			if(ls[i] != ls[lp + i]) return false;
		}
		return true;
	}

	private int[] initKs(char[] cs) {
		int[] ks = new int[26];
		for (char c : cs) ks[c - 'A']++;
		return ks;
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
