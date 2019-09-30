import java.io.*;
import java.util.*;

public class A {


	static class Point {
		double x, y;
		Point(double ax, double ay) {
			x = ax;
			y = ay;
		}
		Point(StringTokenizer st) {
			x = Double.parseDouble(st.nextToken());
			y = Double.parseDouble(st.nextToken());
		}
		double lengthTo(Point p) {
			double dx = p.x - x;
			double dy = p.y - y;
			return Math.sqrt(dx * dx + dy * dy);
		}
	}
    
	private static boolean eq(double a, double b) {
		if(Math.abs(a) < 1)
			return Math.abs(a - b) <= 1e-7;
		return Math.abs(b / a - 1) <= 1e-7;
	}
	
	private static boolean eqz(double a) {
		return eq(Math.abs(a), 0);
	}
	
	private static Point abcd(double a, double b, double c, double d) {
		double x, y;
		if(eqz(a)) {
			if(eqz(b) || eqz(c))
				return null;
			y = 1 / b;
			x = (0 - d * y) / c;
		}
		else if(eqz(c)) {
			if(eqz(d))
				return null;
			y = 0;
			x = 1 / a;
		}
		else {
			y = (-1 / a) / (d / c - b / a);
			x = (1 - b * y) / a;
		}
		//System.err.println(a * x + b * y);
		//System.err.println(c * x + d * y);
		return new Point(x, y);
	}
	
	private static boolean isInside(Point p, Point a[]) {
		int sign = 0;
		for(int i = 0; i < 3; i++) {
			int j = (i + 1) % 3;
			double dx = a[j].x - a[i].x;
			double dy = a[j].y - a[i].y;
			double d = (p.x - a[i].x) * dx + (p.y - a[i].y) * dy;
			if(eqz(d))
				continue;
			int s = (int)Math.signum(d);
			if(sign != 0 && sign != s)
				return false;
			sign = s;
		}
		return true;
	}
	
	private static Point tt(Point a[], Point b[]) {
		double la1 = a[0].lengthTo(a[1]);
		double la2 = a[1].lengthTo(a[2]);
		double la3 = a[2].lengthTo(a[0]);
		double lb1 = b[0].lengthTo(b[1]);
		double lb2 = b[1].lengthTo(b[2]);
		double lb3 = b[2].lengthTo(b[0]);
		double s = lb1 / la1;
		if(s > 1)
			return null;
		if(!eq(s, lb2 / la2))
			return null;
		if(!eq(s, lb3 / la3))
			return null;
		double ca = (a[1].x - a[0].x) * (b[1].x - b[0].x) + (a[1].y - a[0].y) * (b[1].y - b[0].y);
		ca = ca / la1 / lb1;
		double angle = Math.acos(ca);
		double sa = Math.sin(angle);
		double m00 = ca * s;
		double m01 = -sa * s;
		double m10 = sa * s;
		double m11 = ca * s;
		double tx = -(m00 * a[0].x + m01 * a[0].y - b[0].x);
		double ty = -(m10 * a[0].x + m11 * a[0].y - b[0].y);
		
		if(eq(Math.abs(tx), 0) && eq(Math.abs(ty), 0))
			return a[0];
		
		double e00 = 1 - m00;
		double e01 = 0 - m01;
		double e10 = 0 - m10;
		double e11 = 1 - m11;
		
		Point t = abcd(e00, e01, e10, e11);
		if(t == null)
			return null;
		final double f00, f10;
		f00 = t.x;
		f10 = t.y;
		t = abcd(e10, e11, e00, e01);
		if(t == null)
			return null;
		final double f01, f11;
		f01 = t.x;
		f11 = t.y;
	
		//System.err.println(e00 * f00 + e01 * f10);
		//System.err.println(e00 * f01 + e01 * f11);
		//System.err.println(e10 * f00 + e11 * f10);
		//System.err.println(e10 * f01 + e11 * f11);
		Point ret = new Point(
			f00 * tx + f01 * ty,
			f10 * tx + f11 * ty
		);
		/*double rx = m00 * ret.x + m01 * ret.y + tx;
		double ry = m10 * ret.x + m11 * ret.y + ty;
		System.err.println(ret.x - rx);
		System.err.println(ret.y - ry);*/
		if(!isInside(ret, a))
			return null;
		if(!isInside(ret, b))
			return null;
		return ret;
	}
	
	public static void main(String args[]) throws Exception {
//args = new String[] { "A0.in" };
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		int N = Integer.parseInt(in.readLine());
	_CASES:
		for(int c = 1; c <= N; c++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			Point a[] = new Point[3];
			for(int i = 0; i < 3; i++)
				a[i] = new Point(st);
			st = new StringTokenizer(in.readLine());
			Point b[] = new Point[3];
			for(int i = 0; i < 3; i++)
				b[i] = new Point(st);
			for(int i = 0; i < 3; i++) {
				Point tmp = tt(a, b);
				if(tmp != null) {
					System.out.print("Case #" + c + ": ");
					System.out.print(tmp.x + " " + tmp.y);
					System.out.println();
					continue _CASES;
				}
				tmp = a[0];
				a[0] = a[1];
				a[2] = a[2];
				a[2] = tmp;
			}
			System.out.print("Case #" + c + ": ");
			System.out.print("No Solution");
			System.out.println();
		}
	}
}
