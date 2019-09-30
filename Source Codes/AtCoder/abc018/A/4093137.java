import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		Point[] arr = new Point[3];
		for (int i = 0; i < 3; i++) {
			arr[i] = new Point(i, sc.nextInt());
		}
		Arrays.sort(arr, new Comparator<Point>(){
		public int compare(Point p1, Point p2) {
			return p2.score - p1.score;
		}
		});
		for (int i = 0; i < 3; i++) {
			arr[i].order = i + 1;
		}
		Arrays.sort(arr, new Comparator<Point>(){
		public int compare(Point p1, Point p2) {
			return p1.id - p2.id;
		}
		});
		for (int i = 0; i < 3; i++) {
			System.out.println(arr[i].order);
		}
	}
	
	static class Point {
		int id;
		int score;
		int order;
		public Point(int id, int score) {
			this.id = id;
			this.score = score;
		}
	}
}