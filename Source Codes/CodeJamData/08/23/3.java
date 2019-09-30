import java.io.*;
import java.util.*;

public class Cards implements Runnable {
	
	String fileName = "C";
	
	@Override
	public void run() {
		try {
			int nt = nextInt();
			for (int it = 1; it <= nt; it++) {
				int K = nextInt();
				
				int n = nextInt();
				int[] pc = new int[n];
				for (int i = 0; i < n; i++) {
					pc[i] = nextInt();
				}
				int[] ans = new int[n];
				
				int[] cp = new int[n];
				int[] cv = new int[n];
				int cr = n;
				for (int i = 0; i < n; i++) {
					cp[i] = pc[i];
					cv[i] = i;
				}
				int[] np = new int[n];
				int[] nv = new int[n];
				int nr = 0;
				
				for (int nc = K; nc >= 1; nc--) {
					int cur = K - nc + 1;
					int pi = cur % nc;
					if (pi == 0) {
						pi = nc;
					}
					nr = 0;
					for (int i = 0; i < cr; i++) {
						if (cp[i] == pi) {
							ans[cv[i]]  = cur;
						}
						if (cp[i] > pi) {
							np[nr] = cp[i] - pi;
							nv[nr] = cv[i];
							nr++;
						}
						if (cp[i] < pi) {
							np[nr] = nc - pi + cp[i];
							nv[nr] = cv[i];
							nr++;
						}
					}
					{
						{
							int tint = cr;
							cr = nr;
							nr = tint;
						}
						{
							int[] tswap = cp;
							cp = np;
							np = tswap;
						}
						{
							int[] tswap = cv;
							cv = nv;
							nv = tswap;
						}
					}					
				}				
				
				out.format("Case #%d: ", it);
				for (int i = 0; i < n; i++) {
					out.print(ans[i] + " ");
				}				
				out.println();
			}
		} catch (Exception e) {			
			e.printStackTrace();
		} finally {
			out.close();
		}
	}
	
	static {
		Locale.setDefault(Locale.US);
	}		
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;
	public Cards() throws FileNotFoundException {
		in = new BufferedReader(new FileReader(new File(fileName + ".in")));
		out = new PrintWriter(fileName + ".out");
		st = new StringTokenizer("");
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		new Thread(new Cards()).start();	
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
	private long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(next());
	}
}
