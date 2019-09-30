import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.StringTokenizer;

public class ProblemC {

public static void main(String[] args) throws IOException {
		
		ProblemC solver = new ProblemC();
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
			int C = in.nextInt();
			int D = in.nextInt();
			int V = in.nextInt();
			List<Integer> ds = new ArrayList<Integer>();
			for (int i = 0; i < D; i++)
				ds.add(in.nextInt());
			int r = 0;
			
			long curr = 0;
			Iterator<Integer> it = ds.iterator();
			outer:
			while (it.hasNext()) {
				int k = it.next();
				while (k > curr + 1) {
					if (curr >= V) break outer;
					curr += (curr + 1) * C;
					r++;
				}
				curr += 1L * k * C;
			}
			while (curr < V) {
				curr += (curr + 1) * C;
				r++;
			}
			
			out.println("Case #" + t + ": " + r);
		}
		out.flush();
		out.close();
	}
	
//	private boolean check(List<Integer> ds, int v) {
//		int N = ds.size();
//		for (int mask = 0; mask < (1 << N); mask++) {
//			int sum = 0;
//			for (int i = 0; i < N; i++) if ((mask & (1 << i)) > 0) sum += ds.get(i);
//			if (sum == v) return true;
//		}
//		return false;
//	}

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
