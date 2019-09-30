import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().solveA();
		//		new Main().solveB();
		//		new Main().solveC();
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

			System.out.println(res.divide(new BigDecimal("2"), 0, RoundingMode.UP));

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

			boolean res = false;
			if (s.equals(t)) {
				res = false;
			} else {
				res = wkList.get(0).equals(wkSa);
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
		int n = 0;

		try {
			scanner = new Scanner(System.in);
			n = scanner.nextInt();

			int[] wk = new int[n];
			for (int i = 0; i < n; i++) {
				wk[i] = scanner.nextInt();
			}

			Map<Integer, Integer> wkMap = new HashMap<Integer, Integer>();

			Arrays.stream(wk).forEach(elm -> {
				wkMap.merge(elm, 1, (oldV, newV) -> oldV + newV);
			});
			/**
			 * For version
			 */
			//			for (int i = 0; i < wk.length; i++) {
			//				if (!wkMap.containsKey(wk[i])) {
			//					wkMap.put(wk[i], 1);
			//				} else {
			//					wkMap.put(wk[i], wkMap.get(wk[i]) + 1);
			//				}
			//			}

			int res = wkMap.keySet().stream().reduce(0, (sum, entry) -> {
				int num = entry;
				int size = wkMap.get(num);
				if (num == size) {
				} else if (num > size) {
					sum += size;
				} else if (num < size) {
					sum += Math.abs(size - num);
				}
				return sum;
			});

			/**
			 * For version
			 */
			//			for (Iterator<Integer> ite = wkMap.keySet().iterator(); ite.hasNext();) {
			//				int num = ite.next();
			//				int size = wkMap.get(num);
			//				if (num == size) {
			//				} else if (num > size) {
			//					res += size;
			//				} else if (num < size) {
			//					res += Math.abs(size - num);
			//				}
			//			}

			System.out.println(res);

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