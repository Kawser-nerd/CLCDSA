import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] x = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			x[i] = sc.nextInt();;
		}
		sc.close();

		Arrays.parallelSort(x);
		BigInteger ans = BigInteger.valueOf(x[1] - x[0]);
		for (int i = 1; i < n; i++) {
			BigInteger d = BigInteger.valueOf(x[i + 1] - x[i]);
			ans = ans.gcd(d);
		}
		System.out.println(ans.toString());
	}
}