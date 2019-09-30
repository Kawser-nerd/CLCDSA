package round1b;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.Collections;

import qual2011.Kattio;

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		Kattio io;

//		io = new Kattio(System.in, System.out);
//		io = new Kattio(new FileInputStream("src/round1b/B-sample.in"), System.out);
//		io = new Kattio(new FileInputStream("src/round1b/B-small-0.in"), new FileOutputStream("src/round1b/B-small-0.out"));
		io = new Kattio(new FileInputStream("src/round1b/B-large-0.in"), new FileOutputStream("src/round1b/B-large-0.out"));

		int cases = io.getInt();
		for (int i = 1; i <= cases; i++) {
			io.print("Case #" + i + ": ");
			new B().solve(io);
		}
		io.close();
	}

	private void solve(Kattio io) {
		int C = io.getInt(), D = io.getInt();
		ArrayList<Long> vendor = new ArrayList<Long>();

		for (int i = 0; i < C; i++) {
		    int P = io.getInt(), V = io.getInt();
			for (int j = 0; j < V; j++) {
			    vendor.add((long) P * 2);
			}
		}
		D *= 2;
		Collections.sort(vendor);

		long lo = 0, hi = 2000000000000L;
		int iter = 0;
		long best = hi;
		while (hi > lo) {
			long x = (hi + lo) / 2;
			long allowed = vendor.get(0) - x;
			boolean ok = true;
			for (Long v : vendor) {
				// vendor at position v should reach the leftmost position >= allowed
				long t = Math.max(allowed, v - x);
				if (Math.abs(t - v) > x) {
					ok = false;
					break;
				}
				allowed = t + D;
			}
			if (ok) {
				hi = x;
				best = x;
			} else {
				lo = x + 1;
			}
			iter++;
		}
//		System.out.println(iter + " iterations");
		io.println(best / 2.0);
	}
}
