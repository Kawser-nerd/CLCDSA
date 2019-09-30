import java.io.*;
import java.util.*;

public class C {
	private static String fileName = C.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
	private static String inputFileName = fileName + ".in";
	private static String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;

	private void solve() {
		int n = in.nextInt();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextLong();
		}
		Arrays.sort(a);
		Map<Long, BitSet> all = new HashMap<Long, BitSet>();
		Random r = new Random(1243);
		for (;;) {
			BitSet mask = new BitSet();
			long sum = 0;
			for (int i = 0; i < n / 15; i++) {
				if (r.nextBoolean()) {
					mask.set(i);
					sum += a[i];
				}
			}
			BitSet prev = all.get(sum);
			if (all.size() % 10000 == 0) {
				System.out.println(all.size());
			}
			if (prev == null) {
				all.put(sum, mask);
				continue;
			}
			if (!prev.equals(mask)) {
				for (BitSet set : new BitSet[]{prev, mask}) {
					BitSet union = (BitSet) prev.clone();
					union.and(mask);
					prev.andNot(union);
					mask.andNot(union);
					sum = 0;
					for (int i = 0; i < n; i++) {
						if (set.get(i)) {
							out.print(a[i] + " ");
							sum += a[i];
						}
					}
					out.println();
					System.out.print("[" + sum + "]");
				}
				return;
			}
		}
		//out.println("Impossible");
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
			out.println("Case #" + t + ":");
			new C().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
	}
}
