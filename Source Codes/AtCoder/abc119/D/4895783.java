import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int a = scanner.nextInt();
			int b = scanner.nextInt();
			int q = scanner.nextInt();
			scanner.nextLine();
			long[] s = new long[a];
			for (int i = 0; i < a; i++) {
				s[i] = scanner.nextLong();
				scanner.nextLine();
			}
			long[] t = new long[b];
			for (int i = 0; i < b; i++) {
				t[i] = scanner.nextLong();
				scanner.nextLine();
			}
			long[] result = new long[q];
			for (int i = 0; i < q; i++) {
				long x = scanner.nextLong();
				result[i] = nearest(x, s, t);
			}
			Arrays.stream(result).forEach(System.out::println);
		}
	}

	private static long nearest(long x, long[] s, long[] t) {
		long s1, s2, t1, t2;
		int sIndex = Arrays.binarySearch(s, x);
		int tIndex = Arrays.binarySearch(t, x);
		if (sIndex >= 0) {
			s1 = s2 = s[sIndex];
		} else {
			if (sIndex == -1) {
				s1 = s2 = s[0];
			} else if (sIndex == -s.length - 1) {
				s1 = s2 = s[s.length - 1];
			} else {
				s1 = s[-sIndex - 2];
				s2 = s[-sIndex - 1];
			}
		}
		if (tIndex >= 0) {
			t1 = t2 = t[tIndex];
		} else {
			if (tIndex == -1) {
				t1 = t2 = t[0];
			} else if (tIndex == -t.length - 1) {
				t1 = t2 = t[t.length - 1];
			} else {
				t1 = t[-tIndex - 2];
				t2 = t[-tIndex - 1];
			}
		}
		return min(distance(x, s1, t1), distance(x, s1, t2), distance(x, s2, t1), distance(x, s2, t2));
	}

	private static long distance(long x, long s1, long t1) {
		return Math.abs(s1 - t1) + min(Math.abs(s1 - x), Math.abs(t1 - x));
	}

	private static long min(long... x) {
		long min = Long.MAX_VALUE;
		for (long number : x) {
			min = Math.min(min, number);
		}
		return min;
	}
}