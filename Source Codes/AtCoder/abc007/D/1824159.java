import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] a, b;
		long A = sc.nextLong();
		long B = sc.nextLong();
		a = String.valueOf(A).toCharArray();
		b = String.valueOf(B + 1).toCharArray();
		System.out.println(B - A + 1 - (f(b, 0) - f(a, 0)));
	}

	static long f(char[] v, int idx) {
		if (idx == v.length)
			return 0;
		long ret = 0;
		for (int i = 0; i < v[idx] - '0'; ++i) {
			if (i == 4 || i == 9)
				continue;
			ret += pow(8, v.length - 1 - idx);
		}
		if (v[idx] - '0' != 4 && v[idx] - '0' != 9)
			ret += f(v, idx + 1);
		return ret;
	}

	static long pow(long a, long n) {
		long ret = 1;
		for (; n > 0; n >>= 1, a = a * a) {
			if (n % 2 == 1) {
				ret = ret * a;
			}
		}
		return ret;
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}