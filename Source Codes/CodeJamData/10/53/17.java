import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class Main2 implements Runnable {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new Thread(new Main2()).start();
	}

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			run1();
		} catch (IOException e) {
			throw new RuntimeException();
		}
	}

	int nextInt(StreamTokenizer st) throws IOException {
		st.nextToken();
		return (int) st.nval;
	}

	private List<Integer> kmp(String x, String a) {
		String s = a + "$" + x;
		int[] oppa = new int[s.length()];
		oppa[0] = 0;
		int tmp = 0;
		List<Integer> res = new ArrayList<Integer>();
		for (int i = 1; i < s.length(); i++) {
			while (tmp != 0 && s.charAt(tmp) != s.charAt(i)) {
				// System.out.println(i + " " + tmp);
				tmp = oppa[tmp - 1];
			}
			if (s.charAt(tmp) == s.charAt(i))
				tmp++;
			oppa[i] = tmp;
			if (tmp == a.length()) {
				res.add(i - a.length() - a.length());
			}
		}
		return res;
	}

	double nextDouble(StreamTokenizer st) throws IOException {
		st.nextToken();
		return st.nval;
	}

	String nextLine(StreamTokenizer st) throws IOException {
		st.nextToken();
		return st.sval;
	}

	public void run1() throws IOException {
		Scanner sc = new Scanner(new FileReader("input.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		long time = -System.currentTimeMillis();
		int tN = sc.nextInt();
		for (int tn = 1; tn <= tN; tn++) {
			System.out.println(tn);
			int c = sc.nextInt();
			List<Integer> l = new ArrayList<Integer>();
			for (int i = 0; i < c; i++) {
				int pos = sc.nextInt();
				int tmp = sc.nextInt();
				for (int j = 0; j < tmp; j++)
					l.add(pos);
			}
			long res = 0;
			List<int[]> oppa = new ArrayList<int[]>();
			for (int a : l) {
				// System.out.println(a);
				boolean found = false;
				for (int i = 0; i < oppa.size(); i++) {
					int[] tmp = oppa.get(i);
					if (tmp[0] <= a && a <= tmp[1]) {
						found = true;
						oppa.remove(i);
						oppa.add(new int[] { tmp[0] - 1,
								tmp[0] + tmp[1] - 1 - a });
						oppa.add(new int[] { tmp[0] + tmp[1] + 1 - a,
								tmp[1] + 1 });
						long t1 = Math.abs(tmp[0] + tmp[1] - 2 * a) + 1;
						long t2 = tmp[1] - tmp[0] + 1;
						res += (t1 + t2) * (t2 - t1 + 2) / 4;
						break;
					}
				}
				if (!found)
					oppa.add(new int[] { a, a });
				Collections.sort(oppa, new Comparator<int[]>() {
					public int compare(int[] a, int[] b) {
						return a[0] - b[0];
					}
				});
				for (int i = 0; i < oppa.size() - 1; i++) {
					if (oppa.get(i)[1] + 1 == oppa.get(i + 1)[0]) {
						int lb = oppa.get(i)[0];
						int rb = oppa.get(i + 1)[1];
						oppa.remove(i + 1);
						oppa.remove(i);
						oppa.add(new int[] { lb, rb });
					}
				}
				Collections.sort(oppa, new Comparator<int[]>() {
					public int compare(int[] a, int[] b) {
						return a[0] - b[0];
					}
				});
				for (int i = 0; i < oppa.size() - 1; i++) {
					if (oppa.get(i)[1] + 1 == oppa.get(i + 1)[0]) {
						int lb = oppa.get(i)[0];
						int rb = oppa.get(i + 1)[1];
						oppa.remove(i + 1);
						oppa.remove(i);
						oppa.add(new int[] { lb, rb });
					}
				}
				// for (int[] tmp : oppa) {
				// System.out.print("(" + tmp[0] + "," + tmp[1] + ")");
				// }
				// System.out.println();
				// System.out.println(res);
			}
			pw.printf("Case #%d: %d\n", tn, res);
		}
		pw.close();
		System.out.println(time + System.currentTimeMillis());
	}

	long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}
}