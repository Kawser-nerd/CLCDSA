import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int place = 0;
		for (int i = 0; i < n; i++) {
			String s = sc.next();
			int d = sc.nextInt();
			if (d < a) {
				d = a;
			} else if (d > b) {
				d = b;
			}
			if (s.equals("East")) {
				place += d;
			} else {
				place -= d;
			}
		}
		if (place > 0) {
			System.out.print("East ");
		} else if (place < 0) {
			System.out.print("West ");
		}
		System.out.println(Math.abs(place));
	}
}