import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		BigInteger ans = BigInteger.ONE;
		for (int i = 0; i < n; i++) {
			BigInteger bi = new BigInteger(sc.next());
			ans = ans.multiply(bi).divide(ans.gcd(bi));
		}
		sc.close();

		System.out.println(ans.toString());
	}
}