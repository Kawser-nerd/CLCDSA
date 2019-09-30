import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		n %= 12;
		int m = sc.nextInt();
		int minute = n * 60 + m;
		double lon = m * 6;
		double sht = minute * 0.5;
		double ans = Math.abs(lon - sht);
		if (ans > 180) {
			ans = 360 - ans;
		}
		System.out.println(ans);
	}
}