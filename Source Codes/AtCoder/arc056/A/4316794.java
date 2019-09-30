import java.util.*;

public class Main {
	static int count = 0;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextInt();
		long b = sc.nextInt();
		long k = sc.nextInt();
		long l = sc.nextInt();
		long total;
		if (a * l <= b) {
			total = a * k;
		} else {
			total = Math.min((k / l) * b + (k % l) * a, (k / l + 1) * b);
		}
		System.out.println(total);
	}
}