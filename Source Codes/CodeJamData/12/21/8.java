package round1;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

public class A {
	public static void main(String[] args) throws FileNotFoundException {
		Kattio io;

//		io = new Kattio(System.in, System.out);
//		io = new Kattio(new FileInputStream("src/round1/A-sample.in"), System.out);
//		io = new Kattio(new FileInputStream("src/round1/A-small-0.in"), new FileOutputStream("src/round1/A-small-0.out"));
		io = new Kattio(new FileInputStream("src/round1/A-large-0.in"), new FileOutputStream("src/round1/A-large-0.out"));

		int cases = io.getInt();
		for (int i = 1; i <= cases; i++) {
			io.print("Case #" + i + ": ");
			new A().solve(io);
		}
		io.close();
	}

	private void solve(Kattio io) {
		int n = io.getInt(), sum = 0;
		int s[] = new int[n];
		for (int i = 0; i < n; i++) {
		    s[i] = io.getInt();
			sum += s[i];
		}

		for (int i = 0; i < n; i++) {
			double lo = 0.0, hi = 1.0;
			for (int j = 0; j < 200; j++) {
			    double x = (lo + hi) / 2;
				double isc = s[i] + sum*x;
				double left = 1 - x;
				for (int k = 0; k < n; k++) {
				    if (k == i || s[k] > isc) continue;
					double y = (isc - s[k]) / sum;
					left -= y;
				}
				if (left < 0) {
					hi = x;
				} else {
					lo = x;
				}
			}
			if (i > 0) {
				io.print(' ');
			}
			io.print(lo * 100.0);
		}
		io.println();
	}
}
