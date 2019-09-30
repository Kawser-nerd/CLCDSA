import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Point[] points = new Point[n];
		for (int i = 0; i < n; i++) {
			points[i] = new Point(sc.nextInt(), sc.nextInt(), sc.nextInt());
		}
		sc.close();

		int ansX = -1;
		int ansY = -1;
		int ansH = -1;
		label:
		for (int x = 0; x < 101; x++) {
			for (int y = 0; y < 101; y++) {
				int baseH = -1;
				boolean flg = true;
				for (int i = 0; i < n; i++) {
					if (points[i].h > 0) {
						int h = points[i].h + Math.abs(x - points[i].x) + Math.abs(y - points[i].y);
						if (baseH == -1) {
							baseH = h;
						} else if (baseH != h) {
							flg = false;
							break;
						}
					}
				}
				if (flg) {
					for (int i = 0; i < n; i++) {
						if (points[i].h == 0) {
							if (baseH > Math.abs(x - points[i].x) + Math.abs(y - points[i].y)) {
								flg = false;
								break;
							}
						}
					}
					if (!flg) {
						continue;
					}
					ansX = x;
					ansY = y;
					ansH = baseH;
					break label;
				}
			}
		}

		System.out.println(ansX + " " + ansY + " " + ansH);
	}

	static class Point {
		int x;
		int y;
		int h;
		public Point(int x, int y, int h) {
			this.x = x;
			this.y = y;
			this.h = h;
		}
	}
}