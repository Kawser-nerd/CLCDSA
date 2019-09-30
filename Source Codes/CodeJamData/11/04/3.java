import java.io.*;
import java.util.*;

public class D {
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	D() throws IOException {
		in = new BufferedReader(new FileReader("D.large.in"));
		out = new PrintWriter("D.large.out");
		eat("");
		
		int T = nextInt();
		for(int t = 1; t <= T; t++){
			int N = nextInt();
			int[] a = new int[N], b = new int[N];
			for(int i = 0; i < N; i++){
				a[i] = nextInt();
				b[i] = a[i];
			}
			Arrays.sort(b);
			TreeMap<Integer, Integer> M = new TreeMap<Integer, Integer>();
			for(int i = 0; i < N; i++){
				M.put(b[i], i);
			}
			int res = 0;
			for(int i = 0; i < N; i++){
				if(M.get(a[i]) != i){
					res++;
				}
			}
			out.println("Case #" + t + ": " + res);
		}
		
		in.close();
		out.close();
	}
	
	private void eat(String str) {
		st = new StringTokenizer(str);
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

	public static void main(String[] args) throws IOException {
		new D();
	}
}
