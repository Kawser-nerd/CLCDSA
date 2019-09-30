import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;

public class Swatter {

	public static void main(String[] args) throws Exception {
		long start = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		FileWriter w = new FileWriter("output.txt");
		int tests = Integer.parseInt(br.readLine());
		for (int i = 0; i < tests; i++) {
			String[] s = br.readLine().split(" ");
			double f = Double.parseDouble(s[0]);
			double R = Double.parseDouble(s[1]);
			double t = Double.parseDouble(s[2]);
			double r = Double.parseDouble(s[3]);
			double g = Double.parseDouble(s[4]);

			double circle = Math.PI * R * R;
			double empty = 0;
			
			double gg = g - 2 * f;
			if (gg > 0) {
				double x0 = r + f;
				double RR = R - t - f;
				while (x0 < RR) {
					double x1 = x0 + gg;
					double x0y = Math.sqrt(RR * RR - x0 * x0);
					double x1y = Math.sqrt(RR * RR - x1 * x1);
					
					double y0 = r + f;
					while (y0 < x0y) {
						double y1 = y0 + gg;
						double y0x = Math.sqrt(RR * RR - y0 * y0);
						double y1x = Math.sqrt(RR * RR - y1 * y1);
						
						if (x1 < y1x && y1 < x1y) {
							// square
							empty += gg * gg;
						} else if (x1 > y0x && y1 > x0y) {
							// triangle
							double dx = y0x - x0;
							double dy = x0y - y0;
							double ch = Math.sqrt(dx * dx + dy * dy);
							double a = Math.asin(ch / 2 / RR) * 2;
							double seg = RR * RR / 2 * (a - Math.sin(a));
							empty += dx * dy / 2 + seg;
						} else if (y1 > x0y) {
							// trapeze 1
							double dx = x1 - x0;
							double dy = x0y - x1y;
							double ch = Math.sqrt(dx * dx + dy * dy);
							double a = Math.asin(ch / 2 / RR) * 2;
							double seg = RR * RR / 2 * (a - Math.sin(a));
							empty += dx * dy / 2 + seg + (x1 - x0) * (x1y - y0);
						} else if (x1 > y0x) {
							// trapeze 2
							double dx = y0x - y1x;
							double dy = y1 - y0;
							double ch = Math.sqrt(dx * dx + dy * dy);
							double a = Math.asin(ch / 2 / RR) * 2;
							double seg = RR * RR / 2 * (a - Math.sin(a));
							empty += dx * dy / 2 + seg + (y1 - y0) * (y1x - x0);
						} else {
							// pentagon
							double dx = x1 - y1x;
							double dy = y1 - x1y;
							double ch = Math.sqrt(dx * dx + dy * dy);
							double a = Math.asin(ch / 2 / RR) * 2;
							double seg = RR * RR / 2 * (a - Math.sin(a));
							empty += dx * dy / 2 + seg + (y1 - y0) * (y1x - x0) + (x1y - y0) * (x1 - y1x);
						}
						
						y0 += g + 2 * r;
					}
					
					x0 += g + 2 * r;
				}
			}
			System.out.println("circle=" + circle);
			System.out.println("empty=" + empty);
			
			double p = 1 - empty * 4 / circle;
			w.write("Case #" + (i + 1) + ": " + p + "\n");
		}
		br.close();
		w.close();
		System.out.println(System.currentTimeMillis() - start);
	}

}
