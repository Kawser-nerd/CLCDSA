import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Comparator;
import java.util.StringTokenizer;

public class C {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Food {
		final long price, time;

		private Food(long price, long time) {
			this.price = price;
			this.time = time;
		}
	}
	
	static void solve() throws Exception {
//		System.err.println();
//		System.err.println("TEST " + test);
		long money = nextLong();
		long fee = nextLong();
		int n = nextInt();
		Food food[] = new Food[n];
		for (int i = 0; i < n; i++) {
			food[i] = new Food(nextLong(), nextLong() + 1);
		}
		sort(food, new Comparator<Food>() {
			public int compare(Food o1, Food o2) {
				if (o1.price != o2.price) {
					return Long.signum(o1.price - o2.price);
				}
				return Long.signum(o2.time - o1.time);
			}
		});
		{
			int j = 0;
			for (int i = 0; i < n; i++) {
				if (j > 0 && (food[j - 1].price == food[i].price || food[j - 1].time >= food[i].time)) {
					continue;
				}
				food[j++] = food[i];
			}
			if (j < n) {
				n = j;
				food = copyOf(food, n);
			}
		}
//		System.err.print("FOOD");
//		for (int i = 0; i < n; i++) {
//			System.err.print(" (" + food[i].price + " " + food[i].time + ")");
//		}
//		System.err.println();
		BigInteger cost = BigInteger.valueOf(fee);
		long time = 0;
		BigInteger bestCost = cost;
		long bestTime = 0;
		for (int i = 0; i < n; i++) {
			cost = cost.add(BigInteger.valueOf(food[i].time - time).multiply(BigInteger.valueOf(food[i].price)));
			time = food[i].time;
			if (bestCost.multiply(BigInteger.valueOf(time)).compareTo(cost.multiply(BigInteger.valueOf(bestTime))) > 0) {
				bestCost = cost;
				bestTime = time;
			}
		}
//		System.err.println("BEST: " + bestTime + " days for " + bestCost);
		printCase();
		long times = BigInteger.valueOf(money).divide(bestCost).longValue();
//		System.err.println("TIMES " + times);
		out.println(max(ans(money, fee, food, times), ans(money, fee, food, times + 1)));
	}
	
	private static long ans(long money, long fee, Food[] food, long times) {
//		System.err.println("TRY " + times + " times");
		if (times <= 0) {
			return 0;
		}
		long moneyAvg = money / times;
//		System.err.println("Use at most " + moneyAvg);
		if (moneyAvg < fee) {
			return 0;
		}
		long cost = fee;
		long time = 0;
		long nextPrice = Long.MAX_VALUE;
		int n = food.length;
		for (int i = 0; i < n; i++) {
			BigInteger nextCost = BigInteger.valueOf(cost).add(BigInteger.valueOf(food[i].time - time).multiply(BigInteger.valueOf(food[i].price)));
			if (nextCost.compareTo(BigInteger.valueOf(moneyAvg)) > 0) {
				long add = (moneyAvg - cost) / food[i].price;
				cost += food[i].price * add;
				time += add;
				nextPrice = food[i].price;
				break;
			}
			cost = nextCost.longValue();
			time = food[i].time;
		}
//		System.err.println("Result: " + time + " days for " + cost);
		return time * times + (money - cost * times) / nextPrice;
	}

	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}