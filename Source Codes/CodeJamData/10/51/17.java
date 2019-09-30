import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

public class a {
	
	int d, k;
	int ten;
	boolean[] prime;
	int[] el;
	
	private void solve() throws Exception {
		d = nextInt(); k = nextInt();
		ten = 1;
		for (int i = 0; i < d; ++i)
			ten *= 10;
		el = new int[k];
		int max = 0;
		for (int i = 0; i < k; ++i){
			el[i] = nextInt();
			max = Math.max(max, el[i]);
		}
		//out.println();		/////
		if (k == 1){
			out.println("I don't know.");
		}
		else if (k == 2){
			if (el[0] == el[1])
				out.println(el[0]);
			else
				out.println("I don't know.");
		}
		else{
			TreeSet<Integer> q = new TreeSet<Integer>();
			for (int p = max + 1; p <= ten; ++p)
				if (prime[p]){
					BigInteger P = BigInteger.valueOf(p);
					if (el[0] == el[1]){
						q.add(el[0]);
						continue;
					}
					long x1 = el[0], x2 = el[1];
					long y1 = el[1], y2 = el[2];
					if (x1 == 0){
						long tmp = x1;
						x1 = x2;
						x2 = tmp;
						tmp = y1;
						y1 = y2;
						y2 = tmp;
					}
					long x1inv = BigInteger.valueOf(x1).modInverse(P).intValue();
					long X = BigInteger.valueOf(1L - (long)x1inv * x2).modInverse(P).longValue();
					
					long Y = (long)y2 - (long)x2 * x2 * x1inv;
					Y %= p;
					if (Y < 0)
						Y += p;
					long b = (long)((Y * X) % p);
					
					long a = (long)(((long)(y1 - b) * x1inv) % p);
					if (a < 0)
						a += p;
					
					long ne = (long)(((long)el[k - 1] * a + b) % p);
					
					if (check(p, (int)a, (int)b)){
						//out.println(p + " " + a + " " + b + " " + ne);
						q.add((int)ne);
					}
				}
			
			if (q.size() > 1)
				out.println("I don't know.");
			else
				out.println(q.first());
		}
		/*out.println("===");
		TreeSet<Integer> q = new TreeSet<Integer>();
		for (int p = max + 1; p <= ten; ++p)
			if (prime[p]){
				for (int a = 0; a < p; ++a)
					for (int b = 0; b < p; ++b)
						if (check(p, a, b)){
							int ne = (int) (((long)el[k - 1] * a + b) % p);
							out.println(p + " " + a + " " + b + " " + ne);
							q.add(ne);
						}
			}*/
		
	}
	
	private boolean check(int p, int a, int b) {
		for (int i = 1; i < k; ++i)
			if (el[i] != ((long)el[i - 1] * a + b) % p)
				return false;
		return true;
	}

	private void genPrime() {
		prime = new boolean[1000001];
		Arrays.fill(prime, true);
		for (int i = 2; i <= 1000000; ++i)
			if (prime[i])
				for (long j = (long)i * i; j <= 1000000; j += i)
					prime[(int)j] = false;
		prime[0] = prime[1] = false;
	}

	public void run() {
		try {
			genPrime();
			int tc = nextInt();
			for (int it = 1; it <= tc; ++it) {
				System.err.println(it);
				out.print("Case #" + it + ": ");
				solve();
			}
		} catch (Exception e) {
			NOO(e);
		} finally {
			out.close();
		}
	}

	PrintWriter out;
	BufferedReader in;
	StringTokenizer St;

	void NOO(Exception e) {
		e.printStackTrace();
		System.exit(1);
	}

	int nextInt() {
		return Integer.parseInt(nextToken());
	}

	long nextLong() {
		return Long.parseLong(nextToken());
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	String nextToken() {
		while (!St.hasMoreTokens()) {
			try {
				String line = in.readLine();
				St = new StringTokenizer(line);
			} catch (Exception e) {
				NOO(e);
			}
		}
		return St.nextToken();
	}

	private a(String name) {
		try {
			in = new BufferedReader(new FileReader(name + ".in"));
			St = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(name + ".out"));
		} catch (Exception e) {
			NOO(e);
		}
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new a("a").run();
	}

}
