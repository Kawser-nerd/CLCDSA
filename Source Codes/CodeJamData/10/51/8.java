import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class A {
	static boolean SAMPLE;
	Scanner sc;
	
	boolean[] eratos(int n) {
		boolean[] isPrime = new boolean[n];
		fill(isPrime, true);
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i < n; i++) if (isPrime[i]) {
			for (int j = i * 2; j < n; j += i) {
				isPrime[j] = false;
			}
		}
		return isPrime;
	}
	
	boolean[] isPrime = eratos(1000010);
	
	void solve(int caseID) {
		int D = sc.nextInt(), K = sc.nextInt();
		int[] xs = new int[K];
		for (int i = 0; i < K; i++) xs[i] = sc.nextInt();
		if (K == 1) {
			System.out.println("I don't know.");
			return;
		} else if (xs[0] == xs[1]) {
			System.out.println(xs[0]);
			return;
		} else if (K == 2) {
			System.out.println("I don't know.");
			return;
		}
		int max = 0;
		for (int i = 0; i < K; i++) max = max(max, xs[i]);
		int N = 1;
		for (int i = 0; i < D; i++) N *= 10;
		long res = -1;
		for (int P = max + 1; P <= N; P++) if (isPrime[P]) {
			long A = mod(mod(xs[2] - xs[1], P) * pow(xs[1] - xs[0], P - 2, P), P);
			long B = mod(xs[1] - A * xs[0], P);
			boolean ok = true;
			for (int i = 0; i + 1 < K; i++) {
				if (xs[i + 1] != mod(A * xs[i] + B, P)) {
					ok = false;
				}
			}
			if (ok) {
				if (res >= 0 && res != mod(A * xs[K - 1] + B, P)) res = -2;
				else if (res == -1) res = mod(A * xs[K - 1] + B, P);
			}
		}
		if (res < -1) System.out.println("I don't know.");
		else System.out.println(res);
	}
	
	long mod(long a, long P) {
		return (a % P + P) % P;
	}
	
	long pow(long a, long b, long M) {
		a = mod(a, M);
		long res = 1;
		while (b > 0) {
			if ((b & 1) != 0) res = (res * a) % M;
			a = (a * a) % M;
			b >>>= 1;
		}
		return res;
	}
	
	void run() {
		long time = System.currentTimeMillis();
		sc = new Scanner(System.in);
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			double t = (System.currentTimeMillis() - time) * 1e-3;
			if (!SAMPLE) System.err.printf("%03d/%03d %.3f/%.3f%n", caseID, caseN, t, t / (caseID - 1) * caseN);
			System.out.printf("Case #%d: ", caseID);
			solve(caseID);
			System.out.flush();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		if (args.length > 0 && args[0].equals("sample")) {
			try {
				System.setIn(new FileInputStream("A.in"));
				SAMPLE = true;
			} catch (IOException e) {
			}
		}
		new A().run();
	}
}
