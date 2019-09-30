package energy;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class energy {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("energy.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("energy.out")));

		int cases = in(br.readLine());
		for (int test = 1; test <= cases; ++test) {
			pw.print("Case #");
			pw.print(test);
			pw.print(": ");
			pw.println(operate(br));
		}

		br.close();
		pw.close();
	}

	public static long operate(BufferedReader br) throws IOException {
		TreeMap<Integer, Integer> start = new TreeMap<>(), end = new TreeMap<>(), skip = new TreeMap<>();
		Queue<Activity> queue = new PriorityQueue<Activity>();
		StringTokenizer tk = new StringTokenizer(br.readLine());
		long e = lg(tk), r = lg(tk);
		int n = in(tk);
		tk = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; ++i) {
			queue.add(new Activity(in(tk), i));
		}

		long energy = 0;

		while (!queue.isEmpty()) {
			Activity cur = queue.poll();
			Entry<Integer, Integer> next = skip.floorEntry(cur.loc);
			if (next != null && next.getValue() >= cur.loc)
				continue;

			Iterator<Entry<Integer, Integer>> sti = start.descendingMap().tailMap(cur.loc).entrySet().iterator();
			long max = e;
			int maxFind = -1;
			while (sti.hasNext()) {
				Entry<Integer, Integer> ent = sti.next();
				long inc = (cur.loc - ent.getKey()) * r;
				if (inc >= e)
					break;
				inc += ent.getValue();
				if (inc < max) {
					max = inc;
					maxFind = ent.getKey();
				}
			}
			long min = 0;
			int minFind = -1;
			Iterator<Entry<Integer, Integer>> eni = end.tailMap(cur.loc).entrySet().iterator();
			while (eni.hasNext()) {
				Entry<Integer, Integer> ent = eni.next();
				long dec = (ent.getKey() - cur.loc) * r;
				if (dec >= e)
					break;
				dec = ent.getValue() - dec;
				if (dec > min) {
					min = dec;
					minFind = ent.getKey();
				}
			}
			energy += (max - min) * cur.value;
			if (maxFind != -1) {
				skip.put(maxFind, cur.loc);
			} else {
				end.put(cur.loc, (int) max);
			}
			if (minFind != -1) {
				skip.put(cur.loc, minFind);
			} else {
				start.put(cur.loc, (int)min);
			}
		}

		return energy;
	}

	private static final long lg(StringTokenizer tk) {
		return lg(tk.nextToken());
	}

	private static final long lg(String s) {
		return Long.parseLong(s);
	}

	private static final int in(StringTokenizer tk) {
		return in(tk.nextToken());
	}

	private static final int in(String s) {
		return Integer.parseInt(s);
	}

}

class Activity implements Comparable<Activity> {
	int value;
	int loc;

	public Activity(int v, int l) {
		this.value = v;
		this.loc = l;
	}

	@Override
	public int compareTo(Activity o) {
		int dif = o.value - this.value;
		if (dif == 0)
			dif = o.loc - this.loc;
		return dif;
	}

}
