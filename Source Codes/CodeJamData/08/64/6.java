import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class codejam4 {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader in = new BufferedReader(new FileReader("C:\\in.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("C:\\out.txt"));
		int C = Integer.parseInt(in.readLine());
		for (int no = 1; no <= C; no++) {
			int M = Integer.parseInt(in.readLine());
			int[] X = new int[M];
			int[] Y = new int[M];
			int[] trans = new int[M];
			for (int i = 0; i < M - 1; i++) {
				Scanner cin = new Scanner(in.readLine());
				int x = cin.nextInt() - 1;
				int y = cin.nextInt() - 1;
				X[i] = x;
				Y[i] = y;
			}
			int N = Integer.parseInt(in.readLine());
			int[] AX = new int[N];
			int[] AY = new int[N];
			for (int i = 0; i < N - 1; i++) {
				Scanner cin = new Scanner(in.readLine());
				int x = cin.nextInt() - 1;
				int y = cin.nextInt() - 1;
				AX[i] = x;
				AY[i] = y;
			}
			for (int i = 0; i < M; i++)
				trans[i] = i;

			boolean flag = true;
			do {
				int[][] map = new int[M][M];
				for (int i = 0; i < M - 1; i++) {
					map[trans[X[i]]][trans[Y[i]]] = map[trans[Y[i]]][trans[X[i]]] = 1;
				}
				flag = true;
				for (int i = 0; i < N - 1; i++) {
					if (map[AX[i]][AY[i]] == 0) {
						flag = false;
						break;
					}
				}
				if (flag)
					break;
			} while (nextPermutation(trans));

			if (flag) {
				out.write("Case #" + no + ": YES\n");
			} else {
				out.write("Case #" + no + ": NO\n");
			}
		}
		out.flush();
	}
	public static boolean nextPermutation(int[] a) {
		int i, j;
		for (i = a.length - 1; i > 0; i--) {
			if (a[i] > a[i - 1]) {
				break;
			}
		}
		i--;
		if (i == -1)
			return false;
		for (j = a.length - 1; j >= 0; j--) {
			if (a[j] > a[i])
				break;
		}
		int t = a[j];
		a[j] = a[i];
		a[i] = t;
		for (i = i + 1, j = a.length - 1; i < j; i++, j--) {
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		return true;
	}
}
