import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String[] args) {
		//		new Main().solveA();
		//		new Main().solveB();
		new Main().solveC();
		// new Main().solveD();
		//		new Main().solveE();
		//		new Main().solveF();
	}

	private void solveA() {
		Scanner scanner = null;
		int numN = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			System.out.println(numN / 3);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
		Scanner scanner = null;
		int numN = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			Set<String> wkSet = new HashSet<String>();
			for (int i = 0; i < numN; i++) {
				wkSet.add(scanner.next());
			}

			System.out.println(wkSet.size() == 3 ? "Three" : "Four");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveC() {
		Scanner scanner = null;
		int numN = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			String[] wk = new String[numN];

			Map<String, Long> wkMap = new HashMap<String, Long>();
			wkMap.put("M", (long) 0);
			wkMap.put("A", (long) 0);
			wkMap.put("R", (long) 0);
			wkMap.put("C", (long) 0);
			wkMap.put("H", (long) 0);
			for (int i = 0; i < wk.length; i++) {
				wk[i] = scanner.next();
				if (wk[i].startsWith("M")) {
					wkMap.put("M", wkMap.get("M") + 1);
				} else if (wk[i].startsWith("A")) {
					wkMap.put("A", wkMap.get("A") + 1);
				} else if (wk[i].startsWith("R")) {
					wkMap.put("R", wkMap.get("R") + 1);
				} else if (wk[i].startsWith("C")) {
					wkMap.put("C", wkMap.get("C") + 1);
				} else if (wk[i].startsWith("H")) {
					wkMap.put("H", wkMap.get("H") + 1);
				}
			}

			long res = 0;
			res += wkMap.get("M") * wkMap.get("A") * wkMap.get("R");
			res += wkMap.get("M") * wkMap.get("A") * wkMap.get("C");
			res += wkMap.get("M") * wkMap.get("A") * wkMap.get("H");

			res += wkMap.get("M") * wkMap.get("R") * wkMap.get("C");
			res += wkMap.get("M") * wkMap.get("R") * wkMap.get("H");

			res += wkMap.get("M") * wkMap.get("C") * wkMap.get("H");

			res += wkMap.get("A") * wkMap.get("R") * wkMap.get("C");
			res += wkMap.get("A") * wkMap.get("R") * wkMap.get("H");

			res += wkMap.get("A") * wkMap.get("C") * wkMap.get("H");

			res += wkMap.get("R") * wkMap.get("C") * wkMap.get("H");

			System.out.println(res);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveD() {
		Scanner scanner = null;
		int numN = 0;
		int numK = 0;
		int numS = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			System.out.println("");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveE() {
		Scanner scanner = null;
		int numN = 0;
		int numK = 0;
		int numS = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			System.out.println("");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveF() {
		Scanner scanner = null;
		int numN = 0;
		int numK = 0;
		int numS = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();

			System.out.println("");

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}
}