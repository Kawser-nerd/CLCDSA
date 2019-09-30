package round1b;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.Arrays;

public class A {
	public static void main(String[] args) throws FileNotFoundException {
		Kattio io;

//		io = new Kattio(System.in, System.out);
//		io = new Kattio(new FileInputStream("src/round1b/A-sample.in"), System.out);
//		io = new Kattio(new FileInputStream("src/round1b/A-small-attempt0.in"), new FileOutputStream("src/round1b/A-small-0.out"));
		io = new Kattio(new FileInputStream("src/round1b/A-large.in"), new FileOutputStream("src/round1b/A-large.out"));

		int cases = io.getInt();
		for (int i = 1; i <= cases; i++) {
			io.print("Case #" + i + ": ");
			new A().solve(io);
		}
		io.close();
	}

	private void solve(Kattio io) {
        int mySize = io.getInt();
        int n = io.getInt();
        int size[] = new int[n];
        for (int i = 0; i < n; i++) {
            size[i] = io.getInt();
        }
        Arrays.sort(size);

        if (mySize == 1) {
            io.println(n);
            return;
        }
        int best = Integer.MAX_VALUE;
        for (int rem = 0; rem <= n; rem++) {
            int cur = mySize, added = 0;
            for (int i = 0; i < n - rem; i++) {
                if (cur <= size[i]) {
                    cur += (cur-1);
                    added++;
                    i--;
                } else {
                    cur += size[i];
                }
            }
            best = Math.min(best, rem + added);
        }
        io.println(best);
    }
}
