import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		try {
			int t = sc.nextInt();
			int n = sc.nextInt();

			Deque<Integer> q = new ArrayDeque<>();

			for (int i = 0; i < n; i++) {
				q.addLast(sc.nextInt());
			}

			int m = sc.nextInt();
			for (int i = 0; i < m; i++) {
				int x = sc.nextInt();

				while (true) {
					Integer h = q.poll();
					if (h == null || h > x) {
						out.println("no");
						return;
					}

					if (h + t >= x) {
						break;
					}
				}
			}

			out.println("yes");
		} finally {
			sc.close();
		}
	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}