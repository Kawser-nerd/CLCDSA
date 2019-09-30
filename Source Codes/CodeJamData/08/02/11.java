import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;

public class TrainTimetable {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
		// BufferedReader br = new BufferedReader(new
		// InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter("B.out");

		int n = Integer.parseInt(br.readLine());
		for (int t = 0; t < n; t++) {
			int T = Integer.parseInt(br.readLine());
			String e[] = br.readLine().split(" ");
			int na = Integer.parseInt(e[0]);
			int nb = Integer.parseInt(e[1]);
			LinkedList<Integer> adep = new LinkedList<Integer>();
			LinkedList<Integer> bdep = new LinkedList<Integer>();
			LinkedList<Integer> aarr = new LinkedList<Integer>();
			LinkedList<Integer> barr = new LinkedList<Integer>();
			for (int i = 0; i < na; i++) {
				String q[] = br.readLine().split(" ");
				adep.add(gettime(q[0]));
				aarr.add(gettime(q[1]));
			}
			for (int i = 0; i < nb; i++) {
				String q[] = br.readLine().split(" ");
				bdep.add(gettime(q[0]));
				barr.add(gettime(q[1]));
			}
			Collections.sort(adep);
			Collections.sort(bdep);
			Collections.sort(aarr);
			Collections.sort(barr);
			for (int z : aarr)
				for (Iterator<Integer> it = bdep.iterator(); it.hasNext();) {
					int x = it.next();
					if (z + T <= x) {
						it.remove();
						break;
					}
				}
			for (int z : barr)
				for (Iterator<Integer> it = adep.iterator(); it.hasNext();) {
					int x = it.next();
					if (z + T <= x) {
						it.remove();
						break;
					}
				}

			pw.println("Case #" + (t + 1) + ": " + adep.size() + " "
					+ bdep.size());
		}

		pw.close();
	}

	private static Integer gettime(String s) {
		return Integer.parseInt(s.substring(0, 2)) * 60
				+ Integer.parseInt(s.substring(3));
	}
}
