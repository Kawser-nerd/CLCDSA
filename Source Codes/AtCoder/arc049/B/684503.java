import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		new Main().solve();
	}

	void solve() {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int x[] = new int[n];
		int y[] = new int[n];
		int c[] = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = scan.nextInt();
			y[i] = scan.nextInt();
			c[i] = scan.nextInt();
		}

		double left = 0, right = Integer.MAX_VALUE;
		double medium = 0;
		for (int i = 0; i < 100; i++) {
			medium = (double)(left + right) / 2;
			Point square[] = square(x[0], y[0], c[0], medium);
			boolean overlap = false;
			for (int j = 1; j < n; j++) {
				Point sq[] = square(x[j], y[j], c[j], medium);
				if (sq[3].x < square[0].x || sq[3].y > square[0].y || sq[0].x > square[3].x || sq[0].y < square[3].y) {
					overlap = true;
					break;
				}	

				if (square[0].x <= sq[0].x) {
					square[0].x = sq[0].x;
					square[1].x = sq[1].x;
				}
				if (square[0].y >= sq[0].y) {
					square[0].y = sq[0].y;
					square[2].y = sq[2].y;
				}
				if (sq[2].x <= square[2].x) {
					square[2].x = sq[2].x;
					square[3].x = sq[3].x;
				}
				if (square[1].y <= sq[1].y) {
					square[1].y = sq[1].y;
					square[3].y = sq[3].y;
				}
			}
			if (overlap) left = medium;
			else right = medium;
		}

		System.out.println(medium);
	}

	Point[] square(double x, double y, double c, double t) {
		Point square[] = new Point[4];
		square[0] = new Point(x - t / c, y + t / c);
		square[1] = new Point(x - t / c, y - t / c);
		square[2] = new Point(x + t / c, y + t / c);
		square[3] = new Point(x + t / c, y - t / c);
		return square;
	}

	private class Point {
		double x;
		double y;
		Point(double x, double y) {
			this.x = x;
			this.y = y;
		}
	}
}