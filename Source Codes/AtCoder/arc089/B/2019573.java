import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.run();
	}

	Scanner sc = new Scanner(System.in);

	void run() {
		int n = sc.nextInt();
		int k = sc.nextInt();

		int x[] = new int[n];
		int y[] = new int[n];
		int worb[] = new int[n];

		for (int i = 0; i < n; i++) {
			x[i] = (sc.nextInt()) % (2 * k);
			y[i] = (sc.nextInt()) % (2 * k);
			worb[i] = sc.next().startsWith("W") ? 1 : -1;
		}

		int nn = k * 2;
		int mapW[][] = new int[nn][nn];
		int mapB[][] = new int[nn][nn];
		for (int i = 0; i < n; i++) {
			mapW[x[i]][y[i]] += worb[i] == 1 ? 1 : 0;
			mapB[x[i]][y[i]] += worb[i] == -1 ? 1 : 0;
		}

//		System.out.println(Arrays.deepToString(mapW));
//		System.out.println(Arrays.deepToString(mapB));
		
		int m2[][] = new int[nn][nn];

		for (int i = 0; i < nn; i++) {

			int init = 0;
			for (int j = 0; j < nn; j++) {
				init += (j < k) ? mapW[i][j] : mapB[i][j];
			}

			m2[i][0] = init;

			for (int j = 0; j < nn - 1; j++) {
				int j2 = (j + k) % nn;
				m2[i][j + 1] = m2[i][j] - mapW[i][j] + mapB[i][j] + mapW[i][j2] - mapB[i][j2];
			}
		}
		
//		System.out.println(Arrays.deepToString(m2));
		

		int m3[][] = new int[nn][nn];

		for (int j = 0; j < nn; j++) {
			int init = 0;
			for (int i = 0; i < nn; i++) {
				int j2 = (i < k ? j : j + k) % nn;
				init += m2[i][j2];
			}
			m3[0][j] = init;

			for (int i = 0; i < nn - 1; i++) {
				int i2 = (i + k) % nn;
				int j2 = (j + k) % nn;
				m3[i + 1][j] = m3[i][j] - m2[i][j] + m2[i][j2] + m2[i2][j] - m2[i2][j2];
			}
		}
//		System.out.println(Arrays.deepToString(m2));

		int max = 0;
		for (int i = 0; i < nn; i++) {
			for (int j = 0; j < nn; j++) {
				max = Math.max(max, m3[i][j]);
			}
		}
		System.out.println(max);

	}

}