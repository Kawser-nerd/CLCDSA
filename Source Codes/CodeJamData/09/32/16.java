import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

public class P2 {

	public static String p(double x) {
		String a = "";
		a = a + (int) Math.floor(x + 0.0000001) + ".";
		for (int i = 0; i < 8; i++) {
			x = x * 10 - Math.floor(x) * 10;
			a += (int) Math.floor(x);
		}

		return a;
	}

	public static void main(String args[]) throws FileNotFoundException {
		Scanner s = new Scanner(new FileInputStream("B-large.in"));

		int cnt = s.nextInt();

		for (int cases = 0; cases < cnt; cases++) {
			int n = s.nextInt();
			double x = 0, y = 0, z = 0;
			double vx = 0, vy = 0, vz = 0;

			for (int i = 0; i < n; i++) {
				int a = s.nextInt();
				int b = s.nextInt();
				int c = s.nextInt();
				x += a;
				y += b;
				z += c;
				a = s.nextInt();
				b = s.nextInt();
				c = s.nextInt();
				vx += a;
				vy += b;
				vz += c;
			}
			x /= n;
			y /= n;
			z /= n;
			vx /= n;
			vy /= n;
			vz /= n;

			double dist = 0;
			double c = x * x + y * y + z * z;
			double b = 2 * vx * x + 2 * vy * y + 2 * vz * z;
			double a = vx * vx + vy * vy + vz * vz;

			double t;
			if (a == 0) {
				t = 0;
				dist = Math.sqrt(c);
			} else {
				t = -b / (2 * a);
				if (t < 0) {
					t = 0;
					dist = Math.sqrt(c);
				} else {
					dist = Math.sqrt((4 * a * c - b * b) / (4 * a));
				}
			}


			System.out.println("Case #" + (cases + 1) + ": " + p(dist) + " "
					+ p(t));
		}
	}
}
