import java.util.*;

public class Main {

	public static void main(String[] args) {
		new Main().execute();
	}

	public void execute() {
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		final int A = sc.nextInt();
		final int B = sc.nextInt();

		long[] items = new long[N];
		HashMap<Long, Integer> itemCount = new HashMap<>();

		for (int i = 0; i < N; i++) {
			long v = sc.nextLong();
			items[i] = v;
			itemCount.put(v, itemCount.getOrDefault(v, 0) + 1);
		}

		Long[] uniqNums = itemCount.keySet().toArray(new Long[itemCount.size()]);
		Arrays.sort(items);
		Arrays.sort(uniqNums);

		int ai, ar, bi, br;
		ai = uniqNums.length - 1;
		ar = A;
		bi = uniqNums.length - 1;
		br = B;
		while (ar > itemCount.get(uniqNums[ai])) {
			ar -= itemCount.get(uniqNums[ai]);
			ai--;
		}
		while (br > itemCount.get(uniqNums[bi])) {
			br -= itemCount.get(uniqNums[bi]);
			bi--;
		}

		double maxAvg = 0;
		long patterns = 0;

		long sum = 0;
		for (int i = 1; i <= A; i++) {
			sum += items[items.length - i];
		}
		maxAvg = (double) sum / (double) A;

		if (ai == (uniqNums.length - 1)) {
			int bound = Math.max(ar, itemCount.get(uniqNums[uniqNums.length - 1]));
			if (bi == (uniqNums.length - 1)) {
				bound = br;
			}
			for (int i = ar; i <= bound; i++) {
				patterns += combination(itemCount.get(uniqNums[uniqNums.length - 1]), i);
			}
		} else {
			patterns = combination(itemCount.get(uniqNums[ai]), ar);
		}
		System.out.println(maxAvg);
		System.out.println(patterns);
		sc.close();
	}

	private long combination(long n, long r) {
		if (n <= r) {
			return 1L;
		}
		long c = 1L;
		for (long i = 1L; i <= r; i++) {
			c *= ((n - i) + 1);
			c /= i;
		}
		return c;
	}
}