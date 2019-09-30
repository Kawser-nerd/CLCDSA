import java.io.InputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	int n, m;
	Integer[][] siri;

	private boolean canJoin(List<Integer> habatu, Integer c) {
		if (habatu.contains(c)) {
			return false;
		}
		for (int x : habatu) {
			if (siri[c][x] == 0) {
				return false;
			}
		}
		return true;
	}

	private int solve(List<Integer> habatu, Integer c) {

		if (canJoin(habatu, c)) {
			int max = 0;
			List<Integer> newHabatu = new ArrayList<>(habatu);
			newHabatu.add(c);
			for (int i = c; i <= n; i++) {
				max = Math.max(max, solve(newHabatu, i));
			}
			return max;
		} else {
			return habatu.size();
		}
	}

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		n = sc.nextInt();
		m = sc.nextInt();

		siri = new Integer[n + 1][n + 1];
		for (int i = 0; i < n + 1; i++) {
			Arrays.fill(siri[i], 0);
		}

		for (int i = 0; i < m; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();

			siri[x][y] = 1;
			siri[y][x] = 1;

		}

//		System.err.println("---");
//		Arrays.asList(siri).stream().forEach(l -> System.err.println(Arrays.asList(l)));

		int max = 0;
		for (int i = 1; i <= n; i++) {
			max = Math.max(max, solve(new ArrayList<>(), i));
		}

		out.println(max);

		sc.close();
	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}