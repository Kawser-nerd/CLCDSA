import java.util.*;

public class Main {
	static long a;
	static long b;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<Point> list = new ArrayList<>();
		if (n % 2 == 0) {
			for (int i = 1; i < n / 2; i++) {
				list.add(new Point(i, i + 1));
				list.add(new Point(i, n - i));
				list.add(new Point(i + 1, n - i + 1));
				list.add(new Point(n - i, n - i + 1));
			}
			if (n > 4) {
				list.add(new Point(1, n / 2));
				list.add(new Point(n / 2, n));
				list.add(new Point(1, n / 2 + 1));
				list.add(new Point(n / 2 + 1, n));
			}
		} else {
			for (int i = 1; i < n / 2; i++) {
				list.add(new Point(i, i + 1));
				list.add(new Point(i, n - i - 1));
				list.add(new Point(i + 1, n - i));
				list.add(new Point(n - i - 1, n - i));
			}
			list.add(new Point(n / 2, n));
			list.add(new Point(n / 2 + 1, n));
			if (n > 3) {
				list.add(new Point(1, n));
				list.add(new Point(n - 1, n));
			}
		}
		Collections.sort(list, new Comparator<Point>(){
		public int compare(Point p1, Point p2) {
			if (p1.a == p2.a) {
				return p1.b - p2.b;
			} else {
				return p1.a - p2.a;
			}
		}
		});
		StringBuilder sb = new StringBuilder();
		sb.append(list.size()).append("\n");
		for (Point p : list) {
			sb.append(p.a).append(" ").append(p.b).append("\n");
		}
		System.out.print(sb);
	}
	
	static class Point {
		int a;
		int b;
		public Point(int a, int b) {
			this.a = a;
			this.b = b;
		}
	}
}