import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;


public class ProblemC {

	public static void main(String[] args) throws IOException {
		
		ProblemC solver = new ProblemC();
		solver.init();
		solver.solve();
	}

	private void init() {
		
	}
	
	private static class Attack {
		int w,e,s;

		public Attack(int w, int e, int s) {
			super();
			this.w = w;
			this.e = e;
			this.s = s;
		}
		
	}
	
	final static int MIDDLE = 3000;
	
	private void solve() throws IOException {
		 
		Reader in = new Reader(System.in);
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			List<Attack>[] attacks = new List[676060 + 1];
			int N = in.nextInt();
			for (int i = 0; i < N; i++) {
				int d = in.nextInt();
				int n = in.nextInt();
				int w = in.nextInt();
				int e = in.nextInt();
				int s = in.nextInt();
				int dd = in.nextInt();
				int dp = in.nextInt();
				int ds = in.nextInt();
				for (int j = 0; j < n; j++) {
					
					if (attacks[d] == null) attacks[d] = new ArrayList<Attack>();
					attacks[d].add(new Attack(w, e, s));
					
					d += dd;
					w += dp;
					e += dp;
					s += ds;
				}
			}
			
			
			int result = 0;
			int[] wall = new int[MIDDLE * 2];
			
			for (int d = 0; d < attacks.length; d++) if (attacks[d] != null) {
				for (Attack a : attacks[d]) {
					for (int k = MIDDLE + a.w; k < MIDDLE + a.e; k++ ) {
						if (a.s > wall[k]) {
							result++;
							break;
						}
					}
				}
				
				for (Attack a : attacks[d]) {
					for (int k = MIDDLE + a.w; k < MIDDLE + a.e; k++ ) {
						wall[k] = Math.max(wall[k], a.s);
					}
				}
			}
			
			out.println("Case #" + t + ": " + result);
		}
		
		out.flush();
		out.close();
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
