package codejam15;

import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class d {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader(new File("d.in")));
		PrintWriter pw = new PrintWriter("d.out");

		int tc = sc.nextInt();
		for (int t = 1; t <= tc; t++) {

			int x = sc.nextInt();
			int r = sc.nextInt();
			int c = sc.nextInt();

			boolean gw = true;
			int min = Math.min(r, c);

			if (r * c % x != 0) {
				gw = false;
			} else {
				switch (x) {
				case 1:
				case 2:
					gw = true;
					break;
				case 3:
					gw = min >= 2;
					break;
				case 4:
					gw = min >= 3;
					break;
				case 5:
					gw = min >= 3;
					if (min == 3 && c * r == 15) {
						gw = false;
					}
					break;
				case 6:
					gw = min >= 4;
					break;
				default:
					gw = false;
				}
			}

			pw.printf("Case #%d: %s\n", t, gw ? "GABRIEL" : "RICHARD");
		}
		sc.close();
		pw.close();
	}

}
