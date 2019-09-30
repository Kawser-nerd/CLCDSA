import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	boolean check(int x) {
		int a;
		boolean[] z = new boolean[10];
		while (x > 0) {
			a = x % 10;
			z[a] = true;
			x = x / 10;
		}
		return !z[0] && !z[1] && !z[2] && z[3] && !z[4] && z[5] && !z[6] && z[7] && !z[8] && !z[9];
	}

	List<Integer> gen(int k) {
		if (k == 1) {
			List<Integer> result = new ArrayList<>();
			result.add(3);
			result.add(5);
			result.add(7);
			return result;
		}

		List<Integer> result = new ArrayList<>();
		List<Integer> a = gen(k - 1);

		for (int i = 0; i < a.size(); i++) {
			int b = a.get(i);
			result.add(b * 10 + 3);
			result.add(b * 10 + 5);
			result.add(b * 10 + 7);
		}
		return result;

	}

	List<Integer> gen2(int k) {
		List<Integer> result = new ArrayList<>();
		for (int i = 3; i <= k; i++) {
			result.addAll(gen(i));
		}
		return result;
	}

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		int n = sc.nextInt();

		int ans = 0;
		List<Integer> g = gen2(9);
		for (int x : g) {
			if (x > n) {
				break;
			}
			if (check(x)) {
				ans++;
			}
		}

		out.println(ans);

		sc.close();

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}