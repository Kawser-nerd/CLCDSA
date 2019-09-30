import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class C {
	
	static final int INF = 1 << 28, MAX = 30;
	static final double EPS = 1E-9;
	
	static double[][] p = new double[MAX][4];
	static int Q;
	static ArrayList<Double> all = new ArrayList<Double>();
	static void go(int q, double prob) {
		if (q == Q) {
			all.add(prob);
			return;
		}
		for (int i = 0; i < 4; i++)
			go(q+1, prob*p[q][i]);
	}
	
	static void solve() {
		int i, j, k;
		Scanner scan = new Scanner(in);
		int M;
		int T = scan.nextInt();
		double ans;
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");
			M = scan.nextInt();
			Q = scan.nextInt();
			all.clear();
			for (i = 0; i < Q; i++)
				for (j = 0; j < 4; j++)
					p[i][j] = scan.nextDouble();
			go(0, 1);
			Collections.sort(all);
			ans = 0;
			for (i = all.size()-1; i >= Math.max(0, all.size()-M); i--)
				ans += all.get(i);
			out.println(ans);
		}
	}
	
	static String read() {
		try { return in.readLine(); } catch (IOException e) { return null; }
	}
	public static void main(String[] args) throws IOException {
		/*in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new BufferedOutputStream(System.out));*/
		String file = "C-small";
		in = new BufferedReader( new FileReader(file + ".in") );
		out = new PrintWriter( new FileOutputStream(file + "_" + System.currentTimeMillis() + ".out") );
		solve(); out.flush();
	}
	static BufferedReader in; static PrintWriter out;
}
