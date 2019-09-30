import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;


public class CodeJamB {

	static class Point {
		double x;
		double y;
		double z;
		Point() {
			x = 0; y = 0; z = 0;
		}
		Point(Point b) {
			x = b.x;
			y = b.y;
			z = b.z;
		}
		double dot(Point b) {
			return x * b.x + y * b.y + z * b.z;
		}
		double length() {
			return Math.sqrt(dot(this));
		}
		void subtract(Point p) {
			x -= p.x;
			y -= p.y;
			z -= p.z;
		}
		void divide(double p) {
			x = x / p;
			y = y / p;
			z = z / p;
		}
		void multiply(double p) {
			x = x * p;
			y = y * p;
			z = z * p;
		}
		void remove(Point b) {
			Point bv = new Point(b);
			bv.divide(bv.length());
			double r = dot(bv);
			bv.multiply(r);
			subtract(bv);
		}
		public String toString() {
			return "" + x + " " + y + " " + z; 
		}
		
	
	}
	
	public static void main(String[] args) {
		
		try {
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			String line = in.readLine();
			int total = Integer.valueOf(line);
			for (int n=1; n <= total; n++) {
				line = in.readLine();
				int fly = Integer.valueOf(line);
				Point p = new Point();
				Point v = new Point();
				for (int i=0; i<fly; i++) {
					line = in.readLine();
					StringTokenizer st = new StringTokenizer(line);
					p.x += Double.valueOf(st.nextToken());
					p.y += Double.valueOf(st.nextToken());
					p.z += Double.valueOf(st.nextToken());
					v.x += Double.valueOf(st.nextToken());
					v.y += Double.valueOf(st.nextToken());
					v.z += Double.valueOf(st.nextToken());
				}
				p.divide(fly);
				v.divide(fly);
				
				double dis = p.length();
				double tis = 0;
				if (v.length() > 0) {
					Point p2 = new Point(p);
					p2.remove(v);
					Point d = new Point(p2);
					d.subtract(p);
					if (d.dot(v) < 0) {
						// negative direction
						dis = p.length();
						tis = 0;
					} else {
						dis = p2.length();
						tis = d.length() / v.length();
					}
				} else {
				}
				System.out.println(String.format("Case #" + n + ": %.8f %.8f", dis, tis));
			}
		} catch (Throwable e) {
			e.printStackTrace();
		}

	}

}
