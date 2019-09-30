import java.util.*;

public class Main {
	final static long MODULO = 1_000_000_000 + 7;
	static ArrayList<Integer> divs;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long K = sc.nextLong();

		divs = new ArrayList<>();
		for (int i = 1; i * i <= N; ++i) {
			if (N % i == 0) {
				divs.add(i);
				if (i * i != N) {
					divs.add(N / i);
				}
			}
		}
		Collections.sort(divs);
		HashMap<Integer, Long> dp = new HashMap<>();
		for (int d : divs) {
			dp.put(d, pow(K, (d + 1) / 2));
			for (int i = 0; divs.get(i) < d; ++i) {
				if (d % divs.get(i) == 0)
					dp.put(d, (dp.get(d) - dp.get(divs.get(i)) + MODULO) % MODULO);
			}
		}

		long ans = 0;
		for (int d : divs) {
			ans = (ans + dp.get(d) * (d % 2 == 0 ? d / 2 : d)) % MODULO;
		}
		System.out.println(ans);
	}

	static class Div {
		int div;
		int num;

		public Div(int div, int num) {
			this.div = div;
			this.num = num;
		}
	}

	static long pow(long a, long n) {
		long ret = 1;
		for (; n > 0; n >>= 1, a = (a * a) % MODULO) {
			if (n % 2 == 1) {
				ret = (ret * a) % MODULO;
			}
		}
		return ret;
	}
}