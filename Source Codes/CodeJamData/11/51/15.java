import java.util.*;
import static java.lang.Math.*;

public class A {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int zz = 1; zz <= T; zz++){
			int W = in.nextInt();
			int NL = in.nextInt();
			int NU = in.nextInt();
			int G = in.nextInt();
			Point[] L = new Point[NL];
			for(int i = 0; i < NL;i++)
				L[i] = new Point(in.nextInt(), in.nextInt()+1000);
			Point[] U = new Point[NU];
			for(int i = 0; i < NU;i++)
				U[i] = new Point(in.nextInt(), in.nextInt()+1000);
			double start = 0.0;
			System.out.format("Case #%d:\n", zz);
			double area = (areaunder(U, W)-areaunder(L, W))/G;
			double parea = 0.0;
			for(int i = 0; i < G-1; i++){
				double low = start;
				double high = W;
				for(int j = 0; j < 100;j++){
					double mid = (low + high)/2;
					double a = areaunder(U, mid)-areaunder(L, mid) - parea;
					if(a > area){
						high = mid;
					}else{
						low = mid;
					}
				}
				System.out.format("%.09f\n", low);
				parea = areaunder(U, low)-areaunder(L, low);
			}
		}
	}
	static double areaunder(Point[] P, double x){
		double ans = 0;
		for(int i = 0; i + 1 < P.length; i++){
			Point a = P[i];
			Point b = P[i+1];
			if(x >= b.x){
				ans += (b.x-a.x)*(a.y+b.y)/2.;
			}else{
				double y = (b.y-a.y)*(x-a.x)/(b.x-a.x)+a.y;
				ans += (x-a.x)*(a.y+y)/2.;
				break;
			}
		}
		return ans;
	}
	static double eps = 1e-9;
	static boolean EQ(double a, double b){return abs(a-b) < eps;}
	static double SQ(double d){return d*d;}
	static class Point{
		double x, y;
		public Point(double x, double y){this.x = x;this.y = y;}
		Point add(Point p){return new Point(x+p.x, y+p.y);}
		Point sub(Point p){return new Point(x-p.x, y-p.y);}
		Point mult(double d){return new Point(x*d, y*d);}
		double dot(Point p){return x*p.x+ y*p.y;}
		double cross(Point p){return x*p.y - y*p.x;}
		double len(){return hypot(x, y);}
		Point scale(double d){return mult(d/len());}
		double dist(Point p){return sub(p).len();}
		double ang(){return atan2(y, x);}
		static Point polar(double r, double theta){return new Point(r*cos(theta), r*sin(theta));}
		Point rot(double theta){return new Point(x*cos(theta)-y*sin(theta), x*sin(theta)+y*cos(theta));}
		Point perp(){return new Point(-y, x);}
		boolean equals(Point p){return EQ(0, dist(p));}
		double norm(){return dot(this);}
		public String toString(){return String.format("(%.03f, %.03f)", x, y);}
	}	
}
