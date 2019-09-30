import java.util.*;
import java.io.*;

public class WateringPlants {
	class Point {
		double x, y;
		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}
	}
	
	public double sqDist(double x1, double y1, double x2, double y2) {
		return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	}
	
	public double dist(double x1, double y1, double x2, double y2) {
		return Math.sqrt(sqDist(x1, y1, x2, y2));
	}
	
	public List<Point> circleIntr(double x1, double y1, double r1, double x2, double y2, double r2) {
		double d = dist(x1, y1, x2, y2);
		if (d > r1 + r2 || d < Math.abs(r1 - r2)) return new ArrayList<Point>();
		double a = (r1 * r1 - r2 * r2 + d * d) / 2 / d;
		double h = Math.sqrt(r1 * r1 - a * a);
		double px = x1 + a * (x2 - x1) / d;
		double py = y1 + a * (y2 - y1) / d;
		List<Point> res = new ArrayList<Point>();
		res.add(new Point(px + h * (y2 - y1) / d, py - h * (x2 - x1) / d));
		res.add(new Point(px - h * (y2 - y1) / d, py + h * (x2 - x1) / d));
		return res;
	}
	
	public void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			System.out.println("Solving case " + caseNum);
			
			// input
			int N = sc.nextInt();
			int[] X = new int[N];
			int[] Y = new int[N];
			int[] R = new int[N];
			for (int i=0; i < N; i++) {
				X[i] = sc.nextInt();
				Y[i] = sc.nextInt();
				R[i] = sc.nextInt();
			}
			
			// solution
			double l = 0;
			for (int i=0; i < N; i++) if (R[i] > l) l = R[i];
			
			double r = 5000.0;
			
			while (Math.abs(r - l) > 1e-7) {
				double test = (l + r) / 2.0;
				
				Point[] nicePoints = new Point[5000];
				int cnt = 0;
				for (int i=0; i < N; i++)
					nicePoints[cnt++] = new Point(X[i], Y[i] + test - R[i]);
				for (int i=0; i < N; i++)
					for (int j=i+1; j < N; j++) {
						List<Point> lst = circleIntr(X[i], Y[i], test - R[i], X[j], Y[j], test - R[j]);
						for (Point pnt : lst)
							nicePoints[cnt++] = pnt;
					}
				
				boolean find = false;
				for (int i=0; i < cnt && !find; i++)
					for (int j=i; j < cnt && !find; j++) {
						boolean ok = true;
						for (int k=0; k < N; k++)
							if (sqDist(nicePoints[i].x, nicePoints[i].y, X[k], Y[k]) > (test - R[k] + 1e-7) * (test - R[k] + 1e-7) &&
								sqDist(nicePoints[j].x, nicePoints[j].y, X[k], Y[k]) > (test - R[k] + 1e-7) * (test - R[k] + 1e-7)) {
									ok = false;
									break;
								}
						if (ok) find = true;
					}
				
				if (find) r = test; else l = test;
			}
			
			// output
			pw.println("Case #" + caseNum + ": " + (l + r)/2.0);
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new WateringPlants()).doMain();
	}
}