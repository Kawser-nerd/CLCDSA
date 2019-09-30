import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {
	
	private long gcd(long a, long b) {
		return (b==0)?a:gcd(b, a%b);
	}
	public void run() {
		int cases = nextInt();
		for (int cs = 0; cs < cases; ++cs) {
			String s = nextWord();
			String[] cc = s.split("/");
			long nom = Long.parseLong(cc[0]);
			long den = Long.parseLong(cc[1]);
			
			long g = gcd(nom, den);
			nom /= g;
			den /= g;
			
			if (Long.bitCount(den) != 1) {
				out.println("Case #" + (cs+1) + ": impossible");
			}
			else {
				int ans = 1;
				while ((1L << ans) != den && ans < 50) {
					++ans;
				}
				
				if (ans > 40) {
					out.println("Case #" + (cs+1) + ": impossible");
				}
				else {
					int sub = 0;
					while (nom >= (1L << sub)) {
						++sub;
					}
					out.println("Case #" + (cs+1) + ": " + (ans-sub+1));
				}
			}
		}
		out.flush();
	}
	
	private static BufferedReader br = null;
	private static StringTokenizer stk = null;
	private static PrintWriter out = null;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(new File("D:\\A2.txt")));
		out = new PrintWriter("D:\\AA.txt");
		(new Thread(new A())).start();
	}
	
	public void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public String nextLine() {
		try {
			return (br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	public int nextInt() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Integer.parseInt(stk.nextToken());
	}
	
	public long nextLong() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Long.parseLong(stk.nextToken());
	}
	
	public double nextDouble() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Double.parseDouble(stk.nextToken());
	}
	
	public String nextWord() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return (stk.nextToken());
	}
}
