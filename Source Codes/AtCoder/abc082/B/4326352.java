import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		//		new Main().solveA();
		new Main().solveB();
		// new Main().solveC();
		// new Main().solveD();
	}

	private void solveA() {
		Scanner scanner = null;
		String a = "0";
		String b = "0";

		try {
			scanner = new Scanner(System.in);
			a = scanner.next();
			b = scanner.next();

			BigDecimal aB = new BigDecimal(a);
			BigDecimal bB = new BigDecimal(b);

			BigDecimal res = aB.add(bB);

			System.out.println(res.divide(new BigDecimal("2"), 0, RoundingMode.HALF_UP));

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
		Scanner scanner = null;
		String s = "";
		String t = "";

		try {
			scanner = new Scanner(System.in);
			s = scanner.next();
			t = scanner.next();

			List<String> wkList = new ArrayList<String>();
			char[] sA = s.toCharArray();
			char[] tA = t.toCharArray();
			Arrays.sort(sA);
			Arrays.sort(tA);

			String wkSa = new String(sA);
			String wkTa = new StringBuilder(new String(tA)).reverse().toString();
			wkList.add(wkSa);
			wkList.add(wkTa);

			Collections.sort(wkList);

			boolean res = wkList.get(0).equals(wkSa);
			if (s.equals(t)) {
				res = false;
			}
			if (res) {
				System.out.println("Yes");
			} else {
				System.out.println("No");
			}

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveC() {
		Scanner scanner = null;
		int lineAB = 0;
		int lineBC = 0;
		int lineCA = 0;

		try {
			scanner = new Scanner(System.in);
			lineAB = scanner.nextInt();

			System.out.println("");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveD() {
		Scanner scanner = null;
		int lineAB = 0;
		int lineBC = 0;
		int lineCA = 0;

		try {
			scanner = new Scanner(System.in);
			lineAB = scanner.nextInt();

			System.out.println("");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}
}