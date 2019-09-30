import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Point[] points = new Point[n];
		for (int i = 0; i < n; i++) {
			points[i] = new Point(sc.nextInt(), sc.nextInt());
		}
		int max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int d = points[i].getDist2(points[j]);
				if (max < d) {
					max = d;
				}
			}
		}
		System.out.println(Math.sqrt(max));
	}
	
	static class Point {
		int x;
		int y;
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
		public int getDist2(Point p) {
			return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
		}
	}
}