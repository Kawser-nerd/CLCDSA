import java.io.*;
import java.util.*;

public class Trees implements Runnable {
	
	String fileName = "A";
	
	@Override
	public void run() {
		try {
			int nt = nextInt();
			for (int it = 1; it <= nt; it++) {
				long n, A, B, C, D, x0, y0, M;
				n = nextInt();
				A = nextInt();
				B = nextInt();
				C = nextInt();
				D = nextInt();
				x0 = nextInt();
				y0 = nextInt();
				M = nextInt();
				long X = x0, Y = y0;
				long[][] c = new long[3][3];
				make(c, X, Y);				
				for (int i = 1; i <= n-1; i++) {
				  X = (A * X + B) % M;
				  Y = (C * Y + D) % M;
				  make(c, X, Y);
				}
				long r = 0;
				for (int t1 = 0; t1 < 9; t1++) {
					{
						int x1 = t1 % 3;
						int y1 = t1 / 3;
						int x2 = t1 % 3;
						int y2 = t1 / 3;
						int x3 = t1 % 3;
						int y3 = t1 / 3;	
						if ((x1 + x2 + x3) % 3 == 0 && (y1 + y2 + y3) % 3 == 0) {
							r += (c[x1][y1] * (c[x1][y1] - 1) * (c[x1][y1] - 2)) / 6;
						}
					}
					for (int t2 = t1 + 1; t2 < 9; t2++) {
						{
							int x1 = t1 % 3;
							int y1 = t1 / 3;
							int x2 = t2 % 3;
							int y2 = t2 / 3;
							int x3 = t1 % 3;
							int y3 = t1 / 3;	
							if ((x1 + x2 + x3) % 3 == 0 && (y1 + y2 + y3) % 3 == 0) {
								r += (c[x1][y1] * c[x2][y2] * (c[x1][y1] - 1)) / 2;
							}
						}
						{
							int x1 = t1 % 3;
							int y1 = t1 / 3;
							int x2 = t2 % 3;
							int y2 = t2 / 3;
							int x3 = t2 % 3;
							int y3 = t2 / 3;	
							if ((x1 + x2 + x3) % 3 == 0 && (y1 + y2 + y3) % 3 == 0) {
								r += (c[x1][y1] * c[x2][y2] * (c[x2][y2] - 1)) / 2;
							}
						}
						for (int t3 = t2 + 1; t3 < 9; t3++) {
							int x1 = t1 % 3;
							int y1 = t1 / 3;
							int x2 = t2 % 3;
							int y2 = t2 / 3;
							int x3 = t3 % 3;
							int y3 = t3 / 3;	
							if ((x1 + x2 + x3) % 3 == 0 && (y1 + y2 + y3) % 3 == 0) {
								r += c[x1][y1] * c[x2][y2] * c[x3][y3];
							}
						}
					}
				}								
				out.format("Case #%d: %d\n", it, r);
			}
		} catch (Exception e) {			
			e.printStackTrace();
		} finally {
			out.close();
		}
	}
	
	private void make(long[][] c, long x, long y) {
		c[(int) (((x % 3) + 3) % 3)][(int) (((y % 3) + 3) % 3)]++;		
	}

	static {
		Locale.setDefault(Locale.US);
	}		
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;
	public Trees() throws FileNotFoundException {
		in = new BufferedReader(new FileReader(new File(fileName + ".in")));
		out = new PrintWriter(fileName + ".out");
		st = new StringTokenizer("");
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		new Thread(new Trees()).start();	
	}
	
	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(next());
	}
	double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(next());
	}
}
