import java.io.*;
import java.util.*;

class Omino {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			if (r > c) {
				int tmp = r;
				r = c;
				c = tmp;
			}
			boolean bad = r * c % x != 0;
			if (!bad) {
				if (x == 3) {
					//  #
					// ##
					if (r == 1)
						bad = true;
					// 2 x 3 universal box
				} else if (x == 4) {
					//  ##
					// ##
					if (r <= 2)
						bad = true;
					// 3 x 4 universal box
				} else if (x == 5) {
					// 1122##3445
					// 112##33455
					// 122#334455
					if (r <= 2 || r == 3 && c == 5)
						bad = true;
					// 3 x 5 almost-universal box, 4 x 5 universal box
				} else if (x == 6) {
					//  ##
					//  #
					// ###
					if (r <= 3)
						bad = true;
					// 4 x 6 universal box
				} else if (x >= 7) {
					// ##
					// # #
					// ###
					bad = true;
				}
			}
			pw.println("Case #" + t + ": " + (bad ? "RICHARD" : "GABRIEL"));
		}
		pw.close();
	}
}
