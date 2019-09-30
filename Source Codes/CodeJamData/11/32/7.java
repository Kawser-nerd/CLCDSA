import java.io.*;
import java.util.*;
import java.math.*;

public class B {
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	class Segment implements Comparable<Segment> {
		long start;
		long end;
		long modifer;
		
		Segment(long a, long b) {
			start = a;
			end = b;
			modifer = 0;
		}
		
		public int compareTo(Segment o) {
			if(this.modifer > o.modifer) {
				return -1;
			} else if(this.modifer < o.modifer) {
				return 1;
			} else {
				return 0;
			}
		}
	}
	
	private void solve() throws IOException {
		int tests = nextInt();
		
		for(int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			
			
			int L = nextInt();
			long T = nextLong();
			int N = nextInt();
			int C = nextInt();
			
			long[] lengths = new long[C];
			for(int i = 0;  i < C; i++) {
				lengths[i] = nextLong();
			}
			
			Segment[] segments = new Segment[N];
			
			long current = 0;
			
			for(int i = 0; i < N; i++) {
				long length = lengths[i % C];
				segments[i] = new Segment(current, current + length);
				current += length;
			}
			
			long position = T / 2;
			long total_time = 0;
			
			for(int i = 0; i < N; i++) {
				long distance = segments[i].end - position;
				long length = segments[i].end - segments[i].start;
				
				if(distance < 0) {
					distance = 0;
				} else if(distance > length) {
					distance = length;
				}
				
				total_time += 2 * length;
				segments[i].modifer = distance;
			}
			
			Arrays.sort(segments);
			
			long bonus = 0;
			
			for(int i = 0; i < Math.min(L, N); i++) {
				if(segments[i].modifer > 0) {
					bonus += segments[i].modifer;
				} else {
					break;
				}
			}
			
			out.println(total_time - bonus);
		}
	}
	
	public static void main(String[] args) {
		new B().run();
	}
	
	public void run() {
		try {
			//System.setIn(new FileInputStream("input.txt"));
			//System.setOut(new PrintStream(new FileOutputStream("output.txt")));
			
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			st = null;
			
			solve();
			
			in.close();
			out.close();
		} catch(IOException e) {
			e.printStackTrace();
		}
	}
	
	private String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		
		return st.nextToken();
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

}
