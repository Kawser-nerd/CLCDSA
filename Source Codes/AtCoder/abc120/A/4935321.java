import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		//				new Main().solveA();
		new Main().solveA2();
		//		new Main().solveB();
		//		new Main().solveC();
		//		new Main().solveC2();
		// new Main().solveD();
	}

	private void solveA() {

		try (Scanner scanner = new Scanner(System.in)) {
			int numA = 0;
			int numB = 0;
			int numC = 0;
			numA = scanner.nextInt();
			numB = scanner.nextInt();
			numC = scanner.nextInt();

			int wk = numB;
			int res = 0;
			while (wk >= numA && res < numC) {
				wk -= numA;
				res++;
			}

			System.out.println(res);

		}
	}

	private void solveA2() {

		try (Scanner scanner = new Scanner(System.in)) {
			int numA = numA = scanner.nextInt();
			int numB = scanner.nextInt();
			int numC = scanner.nextInt();

			int res = 0;
			if (numB / numA > numC) {
				res = numC;
			} else {
				res = numB / numA;
			}

			System.out.println(res);

		}
	}

	private void solveB() {

		try (Scanner scanner = new Scanner(System.in)) {
			int numA = 0;
			int numB = 0;
			int numK = 0;
			numA = scanner.nextInt();
			numB = scanner.nextInt();
			numK = scanner.nextInt();

			List<Integer> wk = new ArrayList<Integer>();
			for (int i = 1; i <= Math.max(numA, numB); i++) {
				if (numA % i == 0 && numB % i == 0) {
					wk.add(i);
				}
			}

			System.out.println(wk.get(wk.size() - 1 - numK));

		}
	}

	private int getList(List<Character> wk) {

		if (wk.size() < 2) {
			return 0;
		}

		int res = 0;
		int i1 = 0;
		int i2 = 1;
		for (int i = 1; i < wk.size(); i++) {
			if (wk.get(i) != wk.get(i - 1)) {
				i1 = i - 1;
				i2 = i;
				break;
			}
			if (i == wk.size() - 1) {
				return 0;
			}
		}
		while (i2 < wk.size()) {

			char c1 = wk.get(i1);
			char c2 = wk.get(i2);
			if (c1 != c2) {
				wk.remove(i2);
				wk.remove(i1);
				res += 2;
			} else {
				i1 = i2;
				i2 = i2 + 1;
			}
		}
		return getList(wk) + res;
	}

	private void solveC() {

		try (Scanner scanner = new Scanner(System.in)) {
			char[] wkS;
			wkS = scanner.next().toCharArray();

			List<Character> wk = new ArrayList<Character>();
			for (char c : wkS) {
				wk.add(c);
			}

			System.out.println(getList(wk));

		}
	}

	private void solveC2() {

		try (Scanner scanner = new Scanner(System.in)) {
			char[] wkS;
			wkS = scanner.next().toCharArray();

			int cnt0 = 0;
			int cnt1 = 0;
			for (char c : wkS) {
				if (c == '0') {
					cnt0++;
				} else if (c == '1') {
					cnt1++;
				}
			}

			System.out.println(Math.min(cnt0, cnt1) * 2);

		}
	}

	private void solveD() {

		try (Scanner scanner = new Scanner(System.in)) {
			int numN = 0;
			int numK = 0;
			int numS = 0;
			numN = scanner.nextInt();

			System.out.println("");

		}
	}
}