import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ2015R1B implements Runnable {

	private PrintWriter out;
	
	final String file = "B-large";
	Random rnd = new Random(42);

	static class InputData {
        int k, l, s;
        
        String keyboard, target;
		Map<Character, Integer> freqs;
		InputData(FastReader in) throws IOException {
			k = in.nextInt();
			l = in.nextInt();
			s = in.nextInt();	
			keyboard = in.next();
			target = in.next();
			freqs = new HashMap<>();
		}
		
		void solve(PrintWriter out) {
			for(int i = 0; i < k; ++i) {
				char c = keyboard.charAt(i);
				if(freqs.containsKey(c)) {
					freqs.put(c, freqs.get(c)+1);
				} else {
					freqs.put(c, 1);
				}
			}
			
			int maxOverlap = l;
			
			for(int i = 0; i < l; ++i) {
				if(!freqs.containsKey(target.charAt(i))) {
					out.println("0.0");
					return;
				} 
			}
			
			for(int i = 1; i < l; ++i) {
//				System.err.println(target.substring(0, l-i));
//				System.err.println(target.substring(i, l));
				if(target.substring(0, l-i).equals(target.substring(i, l))) {

					maxOverlap = i; 
					break;
				}
			}
//			System.err.println("max overlap " + maxOverlap); 
			
			int maxBananas = (s-l)/maxOverlap+1;
			
			double probPer = 1;
			for(int i = 0; i < l; i++) {
				if(freqs.containsKey(target.charAt(i))) {

					probPer *= ((double) freqs.get(target.charAt(i)))/k;
				} else {
					System.err.println("no map entry???");
					System.err.println(target.charAt(i));
				}
			}
			
			double prob = probPer * (s-(l-1));
			out.println(maxBananas-prob);
		}
	}
	
	static class Solver implements Callable<String> {

		InputData data;
		
		Solver(InputData data) {
			this.data = data;
		}

		@Override
		public String call() throws Exception {
			StringWriter out = new StringWriter();
			data.solve(new PrintWriter(out));
			return out.toString();
		}
		
	}

	public void run() {
		try {
			FastReader in = new FastReader(new BufferedReader(new FileReader(file + ".in")));
			out = new PrintWriter(file + ".out");
		
//			FastReader in = new FastReader(new BufferedReader(new InputStreamReader(System.in)));
//			out = new PrintWriter(System.out);
			
			ScheduledThreadPoolExecutor service = new ScheduledThreadPoolExecutor(7);
			
			int tests = in.nextInt();
			Future<String>[] ts = new Future[tests];
			for (int test = 0; test < tests; ++test) {
				ts[test] = service.submit(new Solver(new InputData(in)));
			}
			for (int test = 0; test < tests; ++test) {
				while (!ts[test].isDone()) {
					Thread.sleep(500);
				}
				System.err.println("Test " + test);
				out.print("Case #" + (test + 1) + ": ");
				out.print(ts[test].get());
			}
			service.shutdown();
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	static class FastReader {
		public FastReader(BufferedReader in) {
			this.in = in;
			eat("");
		}
		
		private StringTokenizer st;
		private BufferedReader in;
		
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
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new GCJ2015R1B().run();
	}
	
}
