package round3;

import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

public class HowBigAreThePockets {
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		for (int i = 1; i <= n; i++) {
			int l = scanner.nextInt();
			int x=0;
			int y=0;
			int direction=1;
			SortedSet<Point> points1 = new TreeSet<Point>();
			SortedSet<Point> points2 = new TreeSet<Point>(new Compare());
			for (int j=0; j < l; j++) {
				String s = scanner.next();
				int t = scanner.nextInt();
				for (int k=0; k < t; k++) {
					for (int m=0; m < s.length(); m++) {
						char c = s.charAt(m);
						if (c=='L') {
							direction++;
							if (direction == 5) {
								direction=1;
							}
						}
						else if (c=='R') {
							direction--;
							if (direction==0) {
								direction=4;
							}
						}
						else if (c=='F') {
							switch (direction) {
							case 1:
								y++;
								points2.add(new Point(2*x,2*y-1));
								break;
							case 2:
								x--;
								points1.add(new Point(2*x+1,2*y));
								break;
							case 3:
								y--;
								points2.add(new Point(2*x,2*y+1));
								break;
							case 4:
								x++;
								points1.add(new Point(2*x-1,2*y));
								break;
							default:
								throw new RuntimeException();
							}
						}
					}
				}
			}
			Set<Point> pockets = new HashSet<Point>();
			Iterator<Point> iter = points1.iterator();
			if (iter.hasNext()) {
				iter.next();
				while (true) {
					Point p1 = iter.next();
					if (iter.hasNext()) {
						Point p2 = iter.next();
						if (p2.x == p1.x) {
							for (int j = p1.y+1; j < p2.y; j+=2) {
								pockets.add(new Point(p1.x, j));
							}
						}
					}
					else {
						break;
					}
				}
			}
			iter = points2.iterator();
			if (iter.hasNext()) {
				iter.next();
				while (true) {
					Point p1 = iter.next();
					if (iter.hasNext()) {
						Point p2 = iter.next();
						if (p2.y == p1.y) {
							for (int j = p1.x+1; j < p2.x; j+=2) {
								pockets.add(new Point(j, p1.y));
							}
						}
					}
					else {
						break;
					}
				}
			}
			System.out.printf("Case #%d: %d\n", i, pockets.size());
		}
	}
	
	public static class Compare implements Comparator<Point> {
		public int compare(Point o1, Point o2) {
			if (o1.y == o2.y) {
				return o1.x-o2.x;
			}
			return o1.y-o2.y;
		}
		
	}
	
	public static class Point implements Comparable<Point> {
		public final int x;
		public final int y;
		
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
		
		public int compareTo(Point o) {
			if (this.x == o.x) {
				return this.y-o.y;
			}
			return this.x-o.x;
		}

		public boolean equals(Object o) {
			if (o.getClass().equals(Point.class)) {
				Point p = (Point) o;
				return p.x==this.x && p.y == this.y;
			}
			return false; 
		}

		@Override
		public int hashCode() {
			return x + y*10000;
		}
		
	}
}
