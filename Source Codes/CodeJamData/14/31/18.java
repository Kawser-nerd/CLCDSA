import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class ProblemA {

	public static void main(String[] args) throws IOException {
		
		ProblemA solver = new ProblemA();
		solver.init();
		solver.solve();
	}
	
	void init() {
	}
	
	private void solve() throws IOException {
		
		Reader in = new Reader(System.in);
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			String[] tokens = in.next().split("/");
			long p = Long.valueOf(tokens[0]);
			long q = Long.valueOf(tokens[1]);
			
			for (long d = 2; d * d <= p; d++) {
				while (p % d == 0 && q % d == 0) {
					p = p/d;
					q = q/d;
				}
			}
			if (q % p == 0) {
				q = q/p;
				p = p/p;
			}
			int r = -1;
			if (Long.bitCount(q) == 1) {
				r = 1 + rec(p,q);
			}
			out.print("Case #" + t + ": ");
			if (r == -1) out.println("impossible");
			else out.println(r);
		}
		
		out.flush();
		out.close();
	}
	
	private int rec(long p, long q) {
		if (p * 2 >= q) return 0;
		else return 1 + rec(p, q/2);
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
