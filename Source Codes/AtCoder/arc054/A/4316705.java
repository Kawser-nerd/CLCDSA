import java.util.*;

public class Main {
	static int count = 0;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		double l = sc.nextInt();
		double x = sc.nextInt();
		double y = sc.nextInt();
		double s = sc.nextInt();
		double d = sc.nextInt();
		double ans = 0;
		if (x >= y) {
			double val = d - s;
			if (val < 0) {
				val += l;
			}
			ans = val / (x + y);
		} else {
			double val1 = s - d;
			if (val1 < 0) {
				val1 += l;
			}
			double ans1 = val1 / (y - x);
			double val2 = d - s;
			if (val2 < 0) {
				val2 += l;
			}
			double ans2 = val2 / (y + x);
			ans = Math.min(ans1, ans2);
		}
		System.out.println(ans);
	}
}