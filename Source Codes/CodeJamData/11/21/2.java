import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	int N;
	char[][] cs;
	
	void read() {
		N = sc.nextInt();
		cs = new char[N][];
		for (int i = 0; i < N; i++) {
			cs[i] = sc.next().toCharArray();
		}
	}
	
	void solve() {
		int[] num = new int[N];
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (cs[i][j] != '.') num[i]++;
		int[] win = new int[N];
		double[] wp = new double[N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) if (cs[i][j] == '1') win[i]++;
			wp[i] = (double)win[i] / num[i];
		}
		double[] owp = new double[N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) if (cs[i][j] != '.') owp[i] += (double)(win[j] - (cs[j][i] - '0')) / (num[j] - 1);
			owp[i] /= num[i];
		}
		double[] oowp = new double[N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) if (cs[i][j] != '.') oowp[i] += owp[j];
			oowp[i] /= num[i];
		}
		for (int i = 0; i < N; i++) {
			System.out.printf("%.10f%n", 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i]);
		}
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
			System.out.printf("Case #%d:%n", caseID);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (A.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new A().run();
	}
}
