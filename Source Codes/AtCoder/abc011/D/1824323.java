import java.util.Arrays;
import java.util.Scanner;

public class Main {

	static double[][] comb = new double[2000][2000];
	//comb[i][j]=C(i,j)*(1/2)^i
	{
		comb[0][0] = 1;
		for (int i = 1; i < comb.length; ++i) {
			for (int j = 0; j <= i; ++j) {
				comb[i][j] = (comb[i - 1][j] + (j > 0 ? comb[i - 1][j - 1] : 0)) * 0.5;
			}
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int N;
		long D;
		long X, Y;
		N = sc.nextInt();
		D = sc.nextLong();
		X = sc.nextLong();
		Y = sc.nextLong();
		X = Math.abs(X);
		Y = Math.abs(Y);
		if (X % D != 0 || Y % D != 0) {
			System.out.println(0);
			return;
		}
		X /= D;
		Y /= D;
		D = 1;
		double ans = 0;
		for (int i = 0; N - 2 * i - X - Y >= 0; ++i) {
			// ??i+X?,??i?
			int j = (int) (N - X - Y - 2 * i);
			if (j % 2 == 1) {
				continue;
			}
			j /= 2;
			//??j+Y????j?
			ans += comb[N][(int) (X + 2 * i)] * comb[(int) (X + 2 * i)][i] * comb[(int) (Y + 2 * j)][j];
		}
		System.out.println(ans);
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}