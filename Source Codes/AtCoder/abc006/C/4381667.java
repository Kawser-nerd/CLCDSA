import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int a = 0;
		int b = 0;
		int c = 0;
		if (m % 2 == 0) {
			b = 0;
		} else {
			b = 1;
			n -= 1;
			m -= 3;
		}
		c = (m - 2 * n) / 2;
		a = n - c;
		if (c * 4 + a * 2 == m  && a >= 0 && c >= 0) {
			System.out.println(a + " " + b + " " + c);
		} else {
			System.out.println("-1 -1 -1");
		}
	}
}