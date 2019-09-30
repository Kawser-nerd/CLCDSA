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
			int R = in.nextInt();
			int C = in.nextInt();
			int W = in.nextInt();
			int r = (C/W) * R;
			r += (W - 1);
			if ((C % W) > 0) r++;
			out.println("Case #" + t + ": " + r);
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
