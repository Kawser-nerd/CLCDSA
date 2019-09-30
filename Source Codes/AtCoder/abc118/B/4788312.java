import java.io.InputStream;
import java.io.PrintStream;
import java.util.BitSet;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int N = sc.nextInt();
		int M = sc.nextInt();

		BitSet a = new BitSet(M);
		a.flip(0, M);

		for (int i = 0; i < N; i++) {
			int K = sc.nextInt();
			BitSet x = new BitSet(M);
			for (int j = 0; j < K; j++) {
				x.set(sc.nextInt() - 1); // ???1???????1??
			}
			a.and(x);
		}

		out.println(a.cardinality());

		sc.close();

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}