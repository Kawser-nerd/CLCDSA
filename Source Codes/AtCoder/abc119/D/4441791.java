import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int A = sc.nextInt();
		int B = sc.nextInt();
		int Q = sc.nextInt();

		long[] s = new long[A+2];
		long[] t = new long[B+2];

		s[0] = -10_0000_000_000L;
		s[A+1] = 10_0000_000_000L;

		t[0] = -10_0000_000_000L;
		t[B+1] = 10_0000_000_000L;

		for(int i=0;i<A;i++) {
			s[i+1] = sc.nextLong();
		}
		for(int i=0;i<B;i++) {
			t[i+1] = sc.nextLong();
		}


		int si = 0;
		int ti = 0;

		for(int i=0;i<Q;i++) {
			long x = sc.nextLong();

			si = Arrays.binarySearch(s, x);
			if(si<0) si = -si -2;
			ti = Arrays.binarySearch(t, x);
			if(ti<0) ti = -ti -2;

			long a1,a2,a3,a4;

			a1 = Math.max(x - s[si], x - t[ti]);
			a2 = Math.min(x-s[si], t[ti+1]-x) * 2 + Math.max(x-s[si], t[ti+1]-x);
			a3 = Math.min(s[si+1]-x, x-t[ti]) * 2 + Math.max(s[si+1]-x, x-t[ti]);
			a4 = Math.max(s[si+1]-x, t[ti+1]-x);

			out.println(Math.min(Math.min(a1, a2), Math.min(a3, a4)));

		}


		sc.close();

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}