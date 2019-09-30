import java.util.*;

public class Main {
	static int count = 0;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		int ans = 0;
		if (h >= 2) {
			ans += (h - 1) * w;
		}
		if (w >= 2) {
			ans += (w - 1) * h;
		}
		System.out.println(ans);
	}
}