import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import java.io.*;
import java.math.*;
import java.util.*;

public class C {
	Scanner sc = new Scanner(System.in);
	
	int M = 1000010;
	
	void solve() {
		long N = sc.nextLong();
		if (N == 1) {
			System.out.println(0);
			return;
		}
		boolean[] isPrime = new boolean[M];
		for (int i = 3; i < M; i += 2) isPrime[i] = true;
		isPrime[2] = true;
		for (int i = 3; i * i < M; i += 2) if (isPrime[i]) {
			for (int j = i * i, k = i * 2; j < M; j += k) {
				isPrime[j] = false;
			}
		}
		long res = 1;
		for (long i = 2; i * i <= N; i++) if (isPrime[(int)i]) {
			int num = 2;
			long j = i * i;
			while (j * i <= N) {
				j *= i;
				num++;
			}
			res += num - 1;
		}
		System.out.println(res);
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
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
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (C.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new C().run();
	}
}
