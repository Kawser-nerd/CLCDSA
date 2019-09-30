import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int y = sc.nextInt();
		int m = sc.nextInt();
		int d = sc.nextInt();
		System.out.println(getDays(2014, 5, 17) - getDays(y, m, d));
	}
	
	static int getDays(int y, int m, int d) {
		if (m <= 2) {
			m += 12;
			y -= 1;
		}
		return 365 * y + y / 4 - y / 100 + y / 400 + 306 * (m + 1) / 10 + d - 429;
	}
}