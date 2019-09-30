import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long ai, ao, at, aj, al, as, az;
		ai = sc.nextLong();
		ao = sc.nextLong();
		at = sc.nextLong();
		aj = sc.nextLong();
		al = sc.nextLong();
		as = sc.nextLong();
		az = sc.nextLong();
		long ans = 0;
		ans = Math.max(ans, ai / 2 * 2 + ao + aj / 2 * 2 + al / 2 * 2);
		if (ai > 0 && aj > 0 && al > 0)
			ans = Math.max(ans, 3 + (ai - 1) / 2 * 2 + ao + (aj - 1) / 2 * 2 + (al - 1) / 2 * 2);
		System.out.println(ans);
	}
}