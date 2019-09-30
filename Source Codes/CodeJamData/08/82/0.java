import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Locale;
import java.util.StringTokenizer;


public class TaskB {

	public static void main(String[] args) throws IOException {
		new TaskB().run();
	}

	BufferedReader br;
	PrintWriter pw;

	private void run() throws IOException {
		Locale.setDefault(Locale.US);
		br = new BufferedReader(new FileReader("b.in"));
		pw = new PrintWriter("b.out");

		int tests = Integer.parseInt(br.readLine().trim());
		for (int test = 1; test <= tests; test++) {
			pw.print("Case #" + test + ": ");
			runtest();
			System.out.println(test);
		}

		br.close();
		pw.close();
	}

	class Item implements Comparable<Item> {
		int l, r;

		public int compareTo(Item o) {
			if (l != o.l) {
				return l - o.l;
			}
			return o.r - r;
		}
	}

	int res;
	HashMap<String, ArrayList<Item>> map;
	Item[] list;

	private void runtest() throws NumberFormatException, IOException {

		int n = Integer.parseInt(br.readLine().trim());

		map = new HashMap<String, ArrayList<Item>>();

		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String color = st.nextToken();
			Item item = new Item();
			item.l = Integer.parseInt(st.nextToken());
			item.r = Integer.parseInt(st.nextToken());

			if (!map.containsKey(color)) {
				map.put(color, new ArrayList<Item>());
			}
			map.get(color).add(item);
		}

		list = new Item[n];
		res = -1;
		for (String color1: map.keySet()) {
			go(color1, null, null);
			for (String color2: map.keySet()) {
				if (color1.compareTo(color2) != 0) {
					go(color1, color2, null);
					for (String color3: map.keySet()) {
						if (color1.compareTo(color3) != 0 && color2.compareTo(color3) != 0) {
							go(color1, color2, color3);
						}
					}
				}
			}
		}

		if (res == -1) {
			pw.println("IMPOSSIBLE");
		} else {
			pw.println(res);
		}
	}

	private void go(String c1, String c2, String c3) {
		int count = 0;
		if (c1 != null) {
			for (Item item : map.get(c1)) {
				list[count++] = item;
			}
		}
		if (c2 != null) {
			for (Item item : map.get(c2)) {
				list[count++] = item;
			}
		}
		if (c3 != null) {
			for (Item item : map.get(c3)) {
				list[count++] = item;
			}
		}

		Arrays.sort(list, 0, count);
		int got = 0;
		int last = 0;
		int i = 0;
		while (i < count) {
			if (last == 10000) {
				break;
			}
			int j = i;
			int maxr = -1;
			while (j < count && list[j].l <= last + 1) {
				if (list[j].r > maxr) {
					maxr = list[j].r;
				}
				j++;
			}

			if (maxr == -1) {
				return;
			}
			last = maxr;
			i = j;
			got++;
		}

		if (last < 10000) {
			return;
		}
		if (res == -1 || got < res) {
			res = got;
		}
	}

}
