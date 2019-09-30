import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int x1 = sc.nextInt();
		int y1 = sc.nextInt();
		int r = sc.nextInt();
		int x2 = sc.nextInt();
		int y2 = sc.nextInt();
		int x3 = sc.nextInt();
		int y3 = sc.nextInt();

		if (d(x2, y2, x1, y1) <= r * r
				&& d(x3, y2, x1, y1) <= r * r
				&& d(x2, y3, x1, y1) <= r * r
				&& d(x3, y3, x1, y1) <= r * r) {
			System.out.println("YES");
			System.out.println("NO");
		} else {
			int rx1 = x1 - r;
			int ry1 = y1 - r;
			int rx2 = x1 + r;
			int ry2 = y1 - r;
			int rx3 = x1 - r;
			int ry3 = y1 + r;
			int rx4 = x1 + r;
			int ry4 = y1 + r;
			if (rx1 >= x2 && rx1 <= x3 && ry1 >= y2 && ry1 <= y3
					&& rx2 >= x2 && rx2 <= x3 && ry2 >= y2 && ry2 <= y3
					&& rx3 >= x2 && rx3 <= x3 && ry3 >= y2 && ry3 <= y3
					&& rx4 >= x2 && rx4 <= x3 && ry4 >= y2 && ry4 <= y3) {
				System.out.println("NO");
				System.out.println("YES");
			} else {
				System.out.println("YES");
				System.out.println("YES");
			}
		}

		sc.close();
	}

	private static int d(int x2, int y2, int x1, int y1) {
		return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	}
}