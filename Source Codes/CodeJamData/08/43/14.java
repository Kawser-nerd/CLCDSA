package round2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

public class P3 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("round2/p3.in"));
		
		FileWriter out = new FileWriter("p3.out");
		
		int n = Integer.parseInt(br.readLine());
		for (int i=1; i<=n; i++) {
			
			double res = solveOne(br);
			System.out.println("Case #" + i + ": " + res);
			out.write("Case #" + i + ": " + res + "\n");
		}
		br.close();
		out.close();
	}

	private static class Point {
		public double x, y, z;

		public Point(double x, double y, double z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}

		public void add(double d, double e, double f) {
			x += d;
			y+=e;
			z+=f;
			
		}
		
	}
	
	private static Point[] points;
	private static int[] power;
	
	private static double solveOne(BufferedReader br) throws Exception {
		int N = Integer.parseInt(br.readLine());
		points = new Point[N];
		power = new int[N];
		Point p = new Point(0,0,0);
		for (int i=0; i<N; i++) {
			String parts[] = br.readLine().split("\\s+");
			points[i] = new Point(Double.parseDouble(parts[0]),Double.parseDouble(parts[1]),Double.parseDouble(parts[2]));
			power[i] = Integer.parseInt(parts[3]);
			p.add(points[i].x,points[i].y,points[i].z);
		}
	
		p = new Point(p.x/N, p.y/N, p.z/N);
		for (double d=1000; d>1e-8; d/=2) {
			boolean m = false;
			
			do {
				m = false;
				// System.out.println(String.format("%.8f  %.8f %.8f %.8f ", d, p.x, p.y, p.z));
				double s = score(p);
				for (int dx=-1; dx<=1; dx++)
					for (int dy=-1; dy<=1; dy++)
						for (int dz=-1; dz<=1; dz++) {
							p.add(d*dx, d*dy, d*dz);
							double s2 = score(p);
							if (s2>=s) {
								p.add(-d*dx, -d*dy, -d*dz);
							} else {
								s = s2;
								m = true;
							}
						}
			} while (m);
		}
		
		return score(p);
	}

	private static double score(Point p) {
		double ret = 0;
		for (int i=0; i<points.length; i++) {
			double d1 = (Math.abs(p.x-points[i].x) + Math.abs(p.y-points[i].y) + Math.abs(p.z-points[i].z)) / power[i];
			if (d1>ret)
				ret = d1;
		}

		return ret;
	}
}
