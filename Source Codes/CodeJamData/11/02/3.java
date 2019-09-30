import java.io.*;
import java.util.*;

public class B {
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	
	int[][] combine;
	boolean[][] opposed;
	int[] seq, res;
	int N, resN;
	
	void solve()
	{
		res = new int[N];
		resN = 0;
		for(int i = 0; i < N; i++){
			res[resN] = seq[i];
			if(resN > 0 && combine[res[resN - 1]][res[resN]] != 0){
				res[resN - 1] = combine[res[resN - 1]][res[resN]];
			}
			else{
				for(int j = 0; j < resN; j++){
					if(opposed[res[j]][res[resN]] == true){
						resN = -1;
						break;
					}
				}
				resN++;
			}
		}
	}
	
	B() throws IOException {
		in = new BufferedReader(new FileReader("B.large.in"));
		out = new PrintWriter("B.large.out");
		eat("");

		int T = nextInt();
		for(int t = 1; t <= T; t++){
			combine = new int[200][200];
			opposed = new boolean[200][200];
			String s;
			int k = nextInt();
			for(int i = 0; i < k; i++){
				s = next();
				int x = (int)(s.charAt(0)), y = (int)(s.charAt(1)), z = (int)(s.charAt(2));
				combine[x][y] = combine[y][x] = z;
			}
			k = nextInt();
			for(int i = 0; i < k; i++){
				s = next();
				int x = (int)(s.charAt(0)), y = (int)(s.charAt(1));
				opposed[x][y] = opposed[y][x] = true;
			}
			N = nextInt();
			s = next();
			seq = new int[N];
			for(int i = 0; i < N; i++){
				seq[i] = (int)(s.charAt(i));
			}
			solve();
			out.print("Case #" + t + ": [");
			for(int i = 0; i + 1 < resN; i++){
				out.print((char)res[i] + ", ");
			}
			if(resN > 0){
				out.print((char)res[resN - 1]);
			}
			out.println("]");
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
		new B();
	}
}
