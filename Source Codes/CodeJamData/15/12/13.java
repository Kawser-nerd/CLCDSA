package round1a;

import java.util.Scanner;

public class B {
	private static long[] times;
	private static long B,N;
	
	private static long started(long t) {
		long ret = 0;
		for (int i = 0; i < times.length; i++) {
			ret += 1 + t / times[i];
		}
		return ret;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caze = 1; caze <= cases; caze++) {
			B = sc.nextInt();
			N = sc.nextInt();
			times = new long[(int)B];
			for (int i = 0; i < times.length; i++) {
				times[i] = sc.nextInt();
			}
			long ret = -1;
			if (B >= N) {
				ret = N;
			}
			if (ret == -1) {
				long left = 0, right = N * 1000000;
				while (left + 1 < right) {
					long med = (left + right) / 2;
					if (started(med) < N) {
						left = med;
					} else {
						right = med;
					}
				}
				long dif = N - started(left);
				for (int i = 0; i < times.length; i++) {
					if (right % times[i] == 0) dif--;
					if (dif == 0) {
						ret = i+1;
						break;
					}
				}
			}
			System.out.println("Case #" + caze + ": " + ret);
		}
	}
}
