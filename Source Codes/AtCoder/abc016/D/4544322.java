import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	private class Matrix22 {
		private double[][] m = new double[2][2];
		
		public Matrix22(double n11, double n12, double n21, double n22) {
			this.m[0][0] = n11;
			this.m[0][1] = n12;
			this.m[1][0] = n21;
			this.m[1][1] = n22;
		}
		
		public double get(int y, int x) {
			return this.m[y][x];
		}
		
		@Override
		public String toString() {
			return "((" + this.m[0][0] + "," + this.m[0][1] + ")," + 
					"(" + this.m[1][0] + "," + this.m[1][1] + ")";
		}
	}

	private class Point {
		public double x;
		public double y;
		
		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}
		
		public Point sub(Point point) {
			this.x -= point.x;
			this.y -= point.y;
			return this;
		}
	
		public Point mul(Matrix22 m) {
			double newX = m.get(0, 0) * this.x + m.get(0, 1) * this.y;
			double newY = m.get(1, 0) * this.x + m.get(1, 1) * this.y;
			this.x = newX;
			this.y = newY;
			return this;
		}
		
		@Override
		public String toString() {
			return "(" + this.x + "," + this.y + ")";
		}
	}
	
	private Matrix22 createRotateMatrix(double rad) {
		return new Matrix22(
				Math.cos(rad), -Math.sin(rad),
				Math.sin(rad), Math.cos(rad));
	}
	
	private Point nextPoint(Scanner in) {
		return new Point(in.nextDouble(), in.nextDouble());
	}
	
	private boolean containSpan(double a1, double a2, double b) {
		if (a1 > a2) {
			double tmp = a1;
			a1 = a2;
			a2 = tmp;
		}
		return (a1 <= b) && (b <= a2);
	}
	
	public void solve() {
		Scanner in = new Scanner(System.in);
		Point A = nextPoint(in);
		Point B = nextPoint(in);
		int N = in.nextInt();
		LinkedList<Point> list = new LinkedList<Main.Point>(); 
		for (int i=0; i<N; i++) {
			list.add(nextPoint(in));
		}
		in.close();
		
		// A??????
		B.sub(A);
		for (Point p : list) {
			p.sub(A);
		}
		A.sub(A);
		// A, B???????????
		double rad = 0.0;
		if (B.x == 0) {
			if (B.y > 0) {
				rad = Math.PI / 2;
			} else {
				rad = -Math.PI / 2;
			}
		} else {
			rad = Math.atan(B.y / B.x);
			if (B.x < 0) {
				rad += Math.PI;
			}
		}
		// Rotate all point to rad
		Matrix22 r = createRotateMatrix(-rad);
		B.mul(r);
		for (Point p : list) {
			p.mul(r);
		}
		
		list.addLast(list.getFirst());
		Point before = null;
		int crossCount = 0;
		for (Point p : list) {
			if (before != null) {
				if (before.y * p.y < 0) {
					double crossX = 0.0;
					if (before.x == p.x) {
						crossX = before.x;
					} else {
						double diffX = p.x - before.x;
						double perBefore = Math.abs(before.y) / (Math.abs(before.y) + Math.abs(p.y));
						double moveX = diffX * perBefore;
						crossX = before.x + moveX;
					}
					if (containSpan(A.x, B.x, crossX)) {
						// coress the chop
						crossCount++;
					}
				}
			}
			before = p;
		}
		
		System.out.println(crossCount / 2 + 1);
	}
	
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}
}