import java.io.*;
import java.util.*;

public class Primes implements Runnable {
	
	String fileName = "B";
	
	int[] c;
	int[] r;
	
	@Override
	public void run() {
		try {
			boolean[] u = new boolean[1000010];			
			{				
				for (int i = 2; i < u.length; i++) {
					if (u[i]) {
						continue;
					}
					int j = 2 * i;
					while (j < u.length) {
						u[j] = true;
						j += i;
					}
				}
			}
			int nt = nextInt();
			c = new int[1000010];
			r = new int[1000010];
			for (int it = 1; it <= nt; it++) {
				long a = nextLong();
				long b = nextLong();
				long p = nextLong();				
				for (long i = a; i <= b; i++) {
					c[(int) (i - a)] = (int) (i - a);
					r[(int) (i - a)] = 1;
				}				
				for (int pi = (int) p; pi < u.length; pi++) {
					if (u[pi]) {
						continue;
					}
					{
						long last = -1;
						for (long i = (a - a % pi); i <= b; i += pi) {
							if (a <= i && i <= b) {														
								if (last != -1) {
									join((int) (last - a), (int) (i - a));
								}
								last = i;
							}							
						}
					}
				}
				int res = 0;
				for (long i = a; i <= b; i++) {
					if (get((int) (i - a)) == i - a) {
						res++;
					}
				}
				out.format("Case #%d: %d\n", it, res);
			}
		} catch (Exception e) {			
			e.printStackTrace();
		} finally {
			out.close();
		}
	}
	
	private int get(int i) {
		if (c[i] != i) {
			c[i] = get(c[i]);
		}
		return c[i];
	}

	private void join(int i, int j) {
		i = get(i);
		j = get(j);
		if (r[i] < r[j]) {
			join(j, i);
			return;
		}
		r[i] += r[j];
		c[j] = i;
	}

	static {
		Locale.setDefault(Locale.US);
	}		
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;
	public Primes() throws FileNotFoundException {
		in = new BufferedReader(new FileReader(new File(fileName + ".in")));
		out = new PrintWriter(fileName + ".out");
		st = new StringTokenizer("");
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		new Thread(new Primes()).start();	
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
