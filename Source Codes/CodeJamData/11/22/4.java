package round1;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class HotDogs {
	static class Point {
		int position, total;

		public Point(int position, int total) {
			this.position = position;
			this.total = total;
		}

	}

	static final double eps = 0.0000000001;
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("hotDog.in"));
		PrintWriter out = new PrintWriter(new File("hotDog.out"));
		int tt = in.nextInt();
		for (int t = 1; t <= tt; t++) {
			System.out.println(t);
			int c = in.nextInt();
			double d = in.nextInt();
			Point[] p = new Point[c];
			for (int i = 0; i < c; i++) {
				int position = in.nextInt();
				int total = in.nextInt();
				p[i] = new Point(position, total);
			}

			double lg = 0, dg = 1000000000;
			dg *= dg;
			int count=0;
			while (dg - lg > eps && count < 100000) {
				count++;
//				System.out.println(dg+" "+lg);
				double s = (dg + lg) / 2;
				boolean moze = true;

				double tmin = -1000000000000000000.0;
				for (int i = 0; moze && i < c; i++) {
					double t1 = Math.max(tmin, p[i].position - s);
					double tlast = t1 + (double) (p[i].total - 1) * (double) d;
					if (tlast - p[i].position > s + eps)
						moze = false;
					else
						tmin = tlast + (double) d;
				}

				if (moze)
					dg = s;
				else
					lg = s;
			}
			System.out.println(dg+" "+lg);

			out.printf("Case #%d: %.10f", t, (lg + dg) / 2);
			out.println();
		}
		out.flush();
		out.close();
	}
}
