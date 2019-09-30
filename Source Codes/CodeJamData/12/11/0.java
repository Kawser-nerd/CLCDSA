import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	int A, B;
	double[] ps;
	
	void read() {
		A = sc.nextInt();
		B = sc.nextInt();
		ps = new double[A];
		for (int i = 0; i < A; i++) ps[i] = sc.nextDouble();
	}
	
	void solve() {
		double min = 1 + B + 1;
		double[] correct = new double[A + 1];
		correct[0] = 1;
		for (int i = 0; i < A; i++) correct[i + 1] = correct[i] * ps[i];
		for (int i = 0; i <= A; i++) min = min(min, ((A - i) + (B - i) + 1) + (1 - correct[i]) * (B + 1));
		System.out.printf("%.10f%n", min);
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
			System.out.printf("Case #%d: ", caseID);
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
