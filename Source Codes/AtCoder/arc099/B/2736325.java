import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		long K = sc.nextLong();
		long ans = 0;
		long add = 1;
		PrintWriter pw = new PrintWriter(System.out);
		// n/s(n)<=m/s(m)
		// ns(m)<=ms(n)
		int cnt = 0;
		while (cnt++ < K) {
			if ((ans + add) * S(ans + add * 10) > (ans + add * 10) * S(ans + add))
				add = add * 10;
			ans += add;
			pw.println(ans);
		}
		pw.close();
	}

	long S(long a) {
		long ret = 0;
		while (a > 0) {
			ret += a % 10;
			a /= 10;
		}
		return ret;
	}

	static void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}