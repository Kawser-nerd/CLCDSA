import java.util.*;
import java.io.*;

public class FlySwatter {
	class Point {
		double x, y;
		public Point(double x, double y) {
			this.x=x; this.y=y;
		}
	}
	
	double area(List<Point> pnt) {
		double res = 0.0;
		for (int i=0; i + 1 < pnt.size(); i++)
			res += (pnt.get(i+1).x - pnt.get(i).x) * (pnt.get(i+1).y + pnt.get(i).y);
		return Math.abs(res / 2.0);
	}
	
	double getAngle(Point pnt) {
		if (pnt.x == 0.0) return Math.PI / 2;
		if (pnt.y == 0.0) return 0.0;
		return Math.atan(pnt.y / pnt.x);
	}
	
	double segm(Point A, Point B, double R) {
		List<Point> pnt = new ArrayList<Point>();
		//System.out.println(A.x + " " + A.y + " " + B.x + " " + B.y + " " + R);
		pnt.add(new Point(0, 0));
		pnt.add(A); pnt.add(B);
		pnt.add(new Point(0, 0));
		double tri = area(pnt);
		double a = getAngle(A), b = getAngle(B);
		double sect = Math.abs(a - b) * R * R / 2.0;
		//System.out.println(sect - tri);
		return sect - tri;
	}
	
	Point intersect(Point A, Point B, double R) {
		if (A.x == B.x) {
			double x = R * R - A.x * A.x;
			if (x < 0.0) x = 0.0;
			return new Point(A.x, Math.sqrt(x));
		} else {
			double x = R * R - A.y * A.y;
			if (x < 0.0) x = 0.0;
			return new Point(Math.sqrt(x), A.y);
		}
	}
	
	void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int cases = sc.nextInt();
		for (int caseNum=0; caseNum<cases; caseNum++) {
			pw.print("Case #" + (caseNum+1) + ": ");
			double f = Double.parseDouble(sc.next());
			double R = Double.parseDouble(sc.next());
			double t = Double.parseDouble(sc.next());
			double r = Double.parseDouble(sc.next());
			double g = Double.parseDouble(sc.next());
			r += f; g -= 2 * f; t += f;
			if (g < 0.0 || R - t < 0.0) {
				pw.println(1.0);
				continue;
			}
			double all = Math.PI * R * R / 4.0;
			double free = 0.0;
			for (int ii=0; ii * (2 * r + g) <= R - t; ii++)
				for (int jj=0; jj * (2 * r + g) <= R - t; jj++) {
					double[] x = new double[5];
					double[] y = new double[5];
					double bx = ii * (2 * r + g), by = jj * (2 * r + g);
					//System.out.println((bx+r)+" "+(by+r)+" "+g+" "+(R-t));
					x[0] = bx + r; y[0] = by + r;
					x[1] = bx + r; y[1] = by + r + g;
					x[2] = bx + r + g; y[2] = by + r + g;
					x[3] = bx + r + g; y[3] = by + r;
					x[4] = x[0]; y[4] = y[0];
					boolean[] inside = new boolean[5];
					for (int i=0; i < 5; i++)
						inside[i] = x[i] * x[i] + y[i] * y[i] <= (R - t) * (R - t);
					if (!inside[0]) continue;
					if (inside[2]) {
						free += g * g;
						continue;
					}
					List<Point> pnt = new ArrayList<Point>();
					List<Point> inter = new ArrayList<Point>();
					for (int i=0; i < 4; i++) {
						if (inside[i]) pnt.add(new Point(x[i], y[i]));
						if (inside[i] != inside[i+1]) {
							Point p = intersect(new Point(x[i], y[i]), new Point(x[i+1], y[i+1]), R - t);
							//System.out.println(p.x + " " + p.y + " " + (R - t));
							pnt.add(p);
							inter.add(p);
						}
					}
					pnt.add(new Point(x[4], y[4]));
					free += area(pnt);
					//System.out.println(free);
					if (inter.size() >= 2)
						free += segm(inter.get(0), inter.get(1), R - t);
					//System.out.println(free);
				}
			pw.println((all - free) / all);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new FlySwatter()).doMain();
	}
}
