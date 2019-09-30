import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class B{
	Scanner sc = new Scanner(System.in);
	PrintStream out = System.out;
	
	double D;
	int N, A;
	double[] t, x, a;
	
	void read() {
		D = sc.nextDouble();
		N = sc.nextInt();
		A = sc.nextInt();
		t = new double[N];
		x = new double[N];
		a = new double[A];
		for (int i = 0; i < N; i++) {
			t[i] = sc.nextDouble();
			x[i] = sc.nextDouble();
		}
		for (int i = 0; i < A; i++) {
			a[i] = sc.nextDouble();
		}
	}
	
	void solve() {
		int N2=N;
		double t2 = t[0];
		for (int i=1; i<N; ++i) {
			if (x[i] >= D) {
				t2 = t[i-1]+(t[i]-t[i-1])*(D-x[i-1])/(x[i]-x[i-1]);
				x[i] = D;
				t[i] = t2;
				N2 = i+1;
				break;
			}
		}
		
		for (int i=0; i<A; ++i) {
			double start = 0.0;
			for (int j=1; j<N2; ++j) {
				t2 = sqrt(2*x[j]/a[i]);
				double start2 = max(t[j], t2)-t2;
				start = max(start, start2);
			}
			
			out.printf("%.8f\n", start+sqrt(2*D/a[i]));
		}

//		for (int i=0; i<A; ++i) {
//		double t = sqrt(2*D/a[i]);
//		out.printf("%2f %2f    ", t, t2);
//		t = max(t, t2);
//		out.printf("%8f\n", t);
//		}
	
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
			System.out.printf("Case #%d:\n", caseID);
			solve();
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		Locale.setDefault(new Locale("en", "US"));
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (B.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new B().run();
	}
}
