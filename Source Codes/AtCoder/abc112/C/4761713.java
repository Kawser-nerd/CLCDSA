import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	int calcH(int cx, int cy, int x, int y, int h) {
		return h + Math.abs(cx - x) + Math.abs(cy - y);
	}

	boolean check(int cx, int cy, int ch, int x, int y, int h) {
		if (h > 0) {
			return ch == calcH(cx, cy, x, y, h);
		} else {
			return ch <= calcH(cx, cy, x, y, h);
		}
	}

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int N = sc.nextInt();
		int[][] xyh = new int[N][3];
		for (int i = 0; i < N; i++) {
			xyh[i] = new int[] { sc.nextInt(), sc.nextInt(), sc.nextInt() };
		}
		sc.close();

		//h?0????xy?????
		int p = -1;
		for (int i = 0; i < N; i++) {
			if (xyh[i][2] > 0) {
				p = i;
				break;
			}
		}

		//????(x,y)????
		for (int cx = 0; cx <= 100; cx++) {

			for (int cy = 0; cy <= 100; cy++)
				next_point: {
					// xyh[p] ?????(cx,cy)?????????H????
					int H = calcH(cx, cy, xyh[p][0], xyh[p][1], xyh[p][2]);

					for (int i = 0; i < N; i++) {
						if (!check(cx, cy, H, xyh[i][0], xyh[i][1], xyh[i][2])) {
							break next_point;
						}
					}
					out.println(cx + " " + cy + " " + H);
					return;

				}
		}

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}