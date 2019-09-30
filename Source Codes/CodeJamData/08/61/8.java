import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class codejam1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader in = new BufferedReader(new FileReader("C:\\in.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("C:\\out.txt"));
		int C = Integer.parseInt(in.readLine());
		for (int no = 1; no <= C; no++) {
			int minW = Integer.MAX_VALUE;
			int maxW = Integer.MIN_VALUE;
			int minH = Integer.MAX_VALUE;
			int maxH = Integer.MIN_VALUE;
			int N = Integer.parseInt(in.readLine());
			ArrayList<Integer> NW = new ArrayList<Integer>();
			ArrayList<Integer> NH = new ArrayList<Integer>();
			for (int i = 0; i < N; i++) {
				Scanner cin = new Scanner(in.readLine());
				int h = cin.nextInt();
				int w = cin.nextInt();
				if (cin.next().equals("BIRD")) {
					minW = Math.min(minW, w);
					maxW = Math.max(maxW, w);
					minH = Math.min(minH, h);
					maxH = Math.max(maxH, h);
				} else {
					NH.add(h);
					NW.add(w);
				}
			}
			int minNW = Integer.MIN_VALUE;
			int maxNW = Integer.MAX_VALUE;
			int minNH = Integer.MIN_VALUE;
			int maxNH = Integer.MAX_VALUE;
			boolean[] flagNW = new boolean[NW.size()];
			boolean[] flagNH = new boolean[NH.size()];
			for (int i = 0; i < NH.size(); i++) {
				int h = NH.get(i);
				int w = NW.get(i);
				if (w >= minW && w <= maxW) {
					if (minH < Integer.MAX_VALUE && h < minH) {
						minNH = Math.max(minNH, h);
					} else if (maxH > Integer.MIN_VALUE && h > maxH) {
						maxNH = Math.min(maxNH, h);
					}
					flagNH[i] = true;
				}
			}
			for (int i = 0; i < NW.size(); i++) {
				int h = NH.get(i);
				int w = NW.get(i);
				if (h >= minH && h <= maxH) {
					if (minW < Integer.MAX_VALUE && w < minW) {
						minNW = Math.max(minNW, w);
					} else if (maxW > Integer.MIN_VALUE && w > maxW) {
						maxNW = Math.min(maxNW, w);
					}
					flagNW[i] = true;
				}
			}
			out.write("Case #" + no + ":\n");
			int M = Integer.parseInt(in.readLine());
			for (int i = 0; i < M; i++) {
				Scanner cin = new Scanner(in.readLine());
				int h = cin.nextInt();
				int w = cin.nextInt();

				boolean flag = false;
				for (int j = 0; j < NH.size(); j++) {
					int th = NH.get(j);
					int tw = NW.get(j);
					if ((flagNH[j] && th == h) || (flagNW[j] && tw == w) || (h == th && w == tw)) {
						flag = true;
						break;
					}
				}
				if (flag) {
					out.write("NOT BIRD\n");
					continue;
				}

				if (h >= minH && h <= maxH && w >= minW && w <= maxW) {
					out.write("BIRD\n");
				} else if (h <= minNH || h >= maxNH || w <= minNW || w >= maxNW) {
					out.write("NOT BIRD\n");
				} else {
					out.write("UNKNOWN\n");
				}
			}
		}
		out.flush();
	}
}
