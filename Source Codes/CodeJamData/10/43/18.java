import java.io.*;
import java.util.*;

public class C {
	private static String fileName = C.class.getSimpleName().replaceFirst("_.*", "");
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	class Start implements Comparable<Start> {
		int x;
		boolean start;
		int myX;
		
		public Start(int x, boolean start) {
			this.x = x;
			this.start = start;
			myX = 4 * x;
			if (!start) {
				myX += 2;
			}
		}

		public Start(int x) {
			myX = 4 * x + 3;
		}

		@Override
		public int compareTo(Start that) {
			return myX - that.myX;
		}
		
		@Override
		public String toString() {
			return x + (start ? "<" : ">");
		}
	}

	private void solve() {
		int r = in.nextInt();
		Map<Integer, List<Start>> map = new TreeMap<Integer, List<Start>>(new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return o2 - o1;
			}
		});
		for (int i = 0; i < r; i++) {
			int x1 = in.nextInt();
			int y1 = in.nextInt();
			int x2 = in.nextInt();
			int y2 = in.nextInt();
			for (int y = y1; y <= y2; y++) {
				if (!map.containsKey(y)) {
					map.put(y, new ArrayList<Start>());
				}
				map.get(y).add(new Start(x1, true));
				map.get(y).add(new Start(x2 + 1, false));
			}
		}
		for (int y : map.keySet()) {
			Collections.sort(map.get(y));
			List<Start> newList = new ArrayList<Start>();
			int open = 0;
			for (Start s : map.get(y)) {
				if (s.start) {
					open++;
					if (open == 1) {
						newList.add(s);
					}
				} else {
					open--;
					if (open == 0) {
						newList.add(s);
					}
				}
			}
			map.put(y, newList);
		}
		int t = 0;
		while (!map.isEmpty()) {
			for (int y : new ArrayList<Integer>(map.keySet())) {
				List<Start> list = map.get(y);
				List<Start> up = map.get(y - 1);
				List<Start> newList = new ArrayList<Start>();
				for (int i = 0; i < list.size(); i += 2) {
					Start s = list.get(i);
					Start e = list.get(i + 1);
					if (!get(up, s.x)) {
						s.x++;
						s.myX += 4;
					}
					if (get(up, e.x)) {
						e.x++;
						e.myX += 4;
					}
					if (s.x == e.x) {
						continue;
					}
					if (!newList.isEmpty() && newList.get(newList.size() - 1).x == s.x) {
						newList.set(newList.size() - 1, e);
					} else {
						newList.add(s);
						newList.add(e);
					}
				}
				if (newList.isEmpty()) {
					map.remove(y);
				} else {
					map.put(y, newList);
				}
			}
			t++;
		}
		out.println(t);
	}

	private boolean get(List<Start> up, int x) {
		if (up == null) {
			return false;
		}
		Start agent = new Start(x);
		int b = - 1 - Collections.binarySearch(up, agent);
		return (b & 1) == 1;
	}

	public static void main(String[] args) throws IOException {
		Locale.setDefault(Locale.US);
		if (args.length >= 2) {
			inputFileName = args[0];
			outputFileName = args[1];
		}
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new C().solve();
		}
		in.close();
		out.close();
	}
}
