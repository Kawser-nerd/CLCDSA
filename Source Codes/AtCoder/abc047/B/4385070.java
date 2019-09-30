import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		try {
			int w = sc.nextInt();
			int h = sc.nextInt();
			int n = sc.nextInt();
			sc.nextLine();

			int left = 0;
			int right = w;
			int bottom = 0;
			int top = h;

			for (int i = 0; i < n; i++) {
				int x = sc.nextInt();
				int y = sc.nextInt();
				int a = sc.nextInt();
				sc.nextLine();

				if (a == 1) {
					if (left < x) left = x;
				} else if (a == 2) {
					if (right > x) right = x;
				} else if (a == 3) {
					if (bottom < y) bottom = y;
				} else if (a == 4) {
					if (top > y) top = y;
				}
			}

			if (right > left && top > bottom) {
				System.out.println((right - left) * (top - bottom));
			} else {
				System.out.println(0);
			}

		} finally {
			sc.close();
		}
	}
}