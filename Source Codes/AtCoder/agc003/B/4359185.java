import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long total = 0;
		long mod = 0;
		for (int i = 0; i < n; i++) {
			long a = sc.nextInt();
			if (a != 0) {
				a += mod;
			}
			total += a / 2;
			mod = a % 2;
		}
		System.out.println(total);
	}
}