import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	static int n;
	static int w;

	@SuppressWarnings("unused")
	public static void main(String[] args) throws IOException {

		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		w = in.nextInt();
		Item[] items = new Item[n];

		boolean isTest1 = true;
		boolean isTest2weight = true;
		boolean isTest3value = true;

		if (n > 30) {
			isTest1 = false;
		}
		for (int i = 0; i < n; i++) {
			int v = in.nextInt();
			int w = in.nextInt();
			items[i] = new Item(v, w);

			if (w > 1000) {
				isTest2weight = false;
			}
			if (v > 1000) {
				isTest3value = false;
			}
		}

		// Restriction of weight
		if (isTest2weight) {
			long[][] dp = new long[n+1][w+1];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j <= w; j++) {
					if (j >= items[i].weight) {
						dp[i+1][j] = Math.max(dp[i][j-items[i].weight] + items[i].value, dp[i][j]);
					} else {
						dp[i+1][j] = dp[i][j];
					}
				}
			}
			System.out.println(dp[n][w]);
		}
		// Restriction of value
		else if (isTest3value) {
			int vMax = 1000;
			long[][] dp = new long[n+1][n * vMax + 1];
			for (int i = 1; i < n * vMax + 1; i++) {
				dp[0][i] = Integer.MAX_VALUE;
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n * vMax + 1; j++) {
					if (j-items[i].value >= 0) {
						dp[i+1][j] = Math.min(dp[i][j], dp[i][j-items[i].value] + items[i].weight);
					} else {
						dp[i+1][j] = dp[i][j];
					}
				}
			}

			long ans = 0;
			for (int i = 0; i < n * vMax + 1; i++) {
				if (dp[n][i] <= w) {
					ans = Math.max(ans, i);
				}
			}
			System.out.println(ans);
		}

		// Restriction only size
		else {
			int n1 = n / 2;
			Item[] items1 = new Item[n1];
			for (int i = 0; i < n1; i++) {
				items1[i] = items[i];
			}

			int n2 = n - n / 2;
			Item[] items2 = new Item[n1];
			for (int i = 0; i < n2; i++) {
				items2[i] = items[n1 + i];
			}
			List<Item2> tmp = new ArrayList<>();

			for (int i = 0; i < 1 << n1; i++) {
				long v1Sum = 0;
				long w1Sum = 0;
				for (int j = 0; j < n1; j++) {
					if ((i >> j & 1) == 1) {
						v1Sum += items1[j].value;
						w1Sum += items1[j].weight;
					}
				}
				tmp.add(new Item2(v1Sum, w1Sum));
			}
			Collections.sort(tmp);
			long MaxV = 0;
			List<Item2> list = new ArrayList<>();
			list.add(new Item2(0, 0));
			for (Item2 item2 : tmp) {
				if (MaxV < item2.value) {
					MaxV = item2.value;
					list.add(item2);
				}
			}

			List<Item2> tmp2 = new ArrayList<>();
			for (int i = 0; i < 1 << n2; i++) {
				long v1Sum = 0;
				long w1Sum = 0;
				for (int j = 0; j < n2; j++) {
					if ((i >> j & 1) == 1) {
						v1Sum += items2[j].value;
						w1Sum += items2[j].weight;
					}
				}
				tmp2.add(new Item2(v1Sum, w1Sum));
			}
			Collections.sort(tmp2);
			MaxV = 0;
			List<Item2> list2 = new ArrayList<>();
			list2.add(new Item2(0, 0));
			for (Item2 item2 : tmp2) {
				if (MaxV < item2.value) {
					MaxV = item2.value;
					list2.add(item2);
				}
			}

			long ans = 0;
			for (int i = 0; i < list2.size(); i++) {
				for (int j = list.size() -1 ; j >= 0; j--) {
					if (list2.get(i).weight + list.get(j).weight <= w) {
						ans = Math.max(ans, list2.get(i).value + list.get(j).value);
						break;
					}
				}
			}
			System.out.println(ans);

		}
	}
	static class Item {
		int value;
		int weight;
		Item(int v, int w) {
			this.value = v;
			this.weight = w;
		}
	}
	static class Item2 implements Comparable<Item2> {
		long value;
		long weight;
		Item2(long v, long w) {
			this.value = v;
			this.weight = w;
		}
		@Override
		public int compareTo(Item2 o) {
			return (int) (this.weight - o.weight);
		}
	}

}