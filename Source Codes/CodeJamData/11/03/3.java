import java.io.*;
import java.util.*;

public class C {
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	C() throws IOException {
		in = new BufferedReader(new FileReader("C.large.in"));
		out = new PrintWriter("C.large.out");
		eat("");
		
		int T = nextInt();
		for(int t = 1; t <= T; t++){
			int N = nextInt(), xor = 0, sum = 0, m = 1000001, c;
			for(int i = 0; i < N; i++){
				c = nextInt();
				xor ^= c;
				sum += c;
				m = Math.min(m, c);
			}
			out.print("Case #" + t + ": ");
			if(xor != 0){
				out.println("NO");
			}
			else{
				out.println(sum - m);
			}
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
		new C();
	}
}
