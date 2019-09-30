import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class ProblemB {
	String input = "B-large.in";
	String output = input.substring(0, input.length() - 2) + "out";

	class Offer implements Comparable<Offer> {
		int a, b, color;

		public int compareTo(Offer arg0) {
			return a - arg0.a;
		}

	}

	int numCases;
	int n;
	Offer[] offers;
	HashMap<String, Integer> cMap;
	ArrayList<Offer>[] buckets;

	void solve() throws FileNotFoundException {
		Scanner sc = new Scanner(new File(input));
		PrintWriter pw = new PrintWriter(output);
		numCases = Integer.parseInt(sc.nextLine());
		for (int cnum = 1; cnum <= numCases; cnum++) {
			n = sc.nextInt();
			offers = new Offer[n];
			cMap = new HashMap<String, Integer>();
			for (int i = 0; i < n; i++) {
				offers[i] = new Offer();
				String color = sc.next();
				if (cMap.containsKey(color)) offers[i].color = cMap.get(color);
				else {
					offers[i].color = cMap.size();
					cMap.put(color, offers[i].color);
				}
				offers[i].a = sc.nextInt() - 1;
				offers[i].b = sc.nextInt() - 1;
			}
			int res = Integer.MAX_VALUE;
			int numColor = cMap.size();
			buckets = new ArrayList[numColor];
			for (int i = 0; i < numColor; i++) buckets[i] = new ArrayList<Offer>();
			for (int i = 0; i < n; i++)
				buckets[offers[i].color].add(offers[i]);
			for (int i = 0; i < numColor; i++)
				for (int j = i; j < numColor; j++)
					for (int k = j; k < numColor; k++) {
						ArrayList<Offer> list = new ArrayList<Offer>();
						list.addAll(buckets[i]);
						if (i != j) list.addAll(buckets[j]);
						if (i != k && j != k) list.addAll(buckets[k]);
						Collections.sort(list);
						res = Math.min(res, getMin(list));
					}
			System.out.println(cnum);
			pw.println("Case #" + cnum + ": " + (res == Integer.MAX_VALUE ? "IMPOSSIBLE" : "" + res));
		}
		sc.close();
		pw.close();
	}

	private int getMin(ArrayList<Offer> list) {
		int res = 0;
		int r = -1;
		int idx = 0;
		while (r < 9999) {
			int mostRight = -1;
			while (idx < list.size()) {
				Offer offer = list.get(idx);
				if (offer.a > r + 1) break;
				mostRight = Math.max(mostRight, offer.b);
				idx++;
			}
			if (mostRight <= r) return Integer.MAX_VALUE;
			r = mostRight;
			res++;
		}
		return res;
	}

	public static void main(String[] args) throws FileNotFoundException {
		System.out.println("Hello");
		new ProblemB().solve();
	}
}
