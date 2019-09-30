package round1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Vector;

public class SpeedLimits2 {

	/**
	 * @param args
	 * @throws IOException 
	 */
	static long modul = 1000000007;
	
	public static long calc(long[] cum, int index) {
		long res = 0;
		int i = 0;
		while (index > 0) {
			res = (res + cum[index]) % modul;
			while (index % st2[i] == 0) i++;
			i--;
			index -= st2[i];
		}
		return res;
	}
	
	public static void update(long[] cum, int index, long hm) {
		int i = 0;
		while (index < cum.length) {
			cum[index] = (cum[index] + hm) % modul;
			while (index % st2[i] == 0) i++;
			i--;
			index += st2[i];			
		}
	}
	
	static int[] st2;
	static void precalc() {
		st2 = new int[25];
		st2[0] = 1;
		for (int i = 1; i < 25; i++)
			st2[i] = st2[i-1] * 2;
	}
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new FileReader(new File(
				"C-large.in"))));
		BufferedWriter wr = new BufferedWriter(
				new FileWriter(new File("c2.out")));
		int tests = sc.nextInt();
		precalc();
		for (int test = 1; test <= tests; test++) {
			int n = sc.nextInt(), m = sc.nextInt();
			long x = sc.nextLong(), y = sc.nextLong(), z = sc.nextLong();
			long[] a = new long[m];
			for (int i = 0; i < m; i++)
				a[i] = sc.nextLong();
			long[] s = new long[n];
			Vector<Long> r = new Vector<Long>();
			HashSet<Long> set = new HashSet<Long>();
			for (int i = 0; i < n; i++) {
				s[i] = a[i % m];
				if (!set.contains(s[i])) {
					r.add(s[i]);
					set.add(s[i]);
				}
				a[i % m] = (x * a[i % m] + y * (i + 1)) % z;
			}
			Collections.sort(r);
			HashMap<Long, Integer> map = new HashMap<Long, Integer>();
			for (int i = 0; i < r.size(); i++)
				map.put(r.get(i), i+1);
			long[] cum = new long[r.size()+1];
			for (int i = 0; i < n; i++) {
				update(cum, map.get(s[i]), 1+calc(cum, map.get(s[i])-1));
			}
//			long inc[] = new long[n];
//			for (int i = 0; i < n; i++)
//				inc[i] = 1;
//			for (int i = 1; i < n; i++)
//				for (int j = 0; j < i; j++)
//					if (s[i] > s[j])
//						inc[i] = (inc[i] + inc[j]) % modul;
			long res = calc(cum, cum.length-1);
//			for (int i = 0; i < n; i++)
//				res = (res + inc[i]) % modul;
			wr.write("Case #" + test + ": " + res + "\n");
			System.out.println(res);
		}
		wr.close();
		sc.close();
	}

}
