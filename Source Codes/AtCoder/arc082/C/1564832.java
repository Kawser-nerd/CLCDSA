import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {
	
	static class Point {
		int x, y;
		public Point(int xx, int yy) {
			x = xx;
			y = yy;
		}
		int cross(Point o) {
			return x * o.y - o.x * y;
		}
		Point sub(Point o){
			return new Point(x - o.x, y - o.y);
		}
	}
	
	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens()) {
				String cad = br.readLine();
				if (cad == null)
					return null;
				tk=new StringTokenizer(cad);
			}
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
		public long nextLong() throws NumberFormatException, IOException{
			return Long.valueOf(next());
		}
		public double nextDouble() throws NumberFormatException, IOException{
			return Double.valueOf(next());
		}
	}
	
	static long mod = 998244353;
	static long[] pow2;
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		Scanner sc = new Scanner();
		int N = sc.nextInt();
		Point[] p = new Point[N];
		for(int i = 0; i < N; i++)
			p[i] = new Point(sc.nextInt(), sc.nextInt());
		pow2 = new long[N + 1];
		pow2[0] = 1;
		for(int i = 1; i <= N; i++)
			pow2[i] = (pow2[i - 1] * 2) % mod;
		long sub = 1;
		for(int i = 0; i < N; i++) { 
			sub++;
			for(int j = i + 1; j < N; j++) {
				int count = 0;
				for(int k = j + 1; k < N; k++) {
					if (p[j].sub(p[i]).cross(p[k].sub(p[i])) == 0)
						count++;
				}
				sub = (sub + pow2[count]) % mod;
			}
		}
		System.out.println((pow2[N] - sub + mod) % mod);
	}

}