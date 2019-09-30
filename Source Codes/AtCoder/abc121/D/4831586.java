import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		//		new Main().solveA();
		//		new Main().solveB();
		//		new Main().solveC();
		//		new Main().solveD();
		//		new Main().solveD2();
		new Main().solveD3();
	}

	private void solveA() {
		Scanner scanner = null;
		int numH = 0;
		int numW = 0;
		int h = 0;
		int w = 0;

		try {
			scanner = new Scanner(System.in);
			numH = scanner.nextInt();
			numW = scanner.nextInt();
			h = scanner.nextInt();
			w = scanner.nextInt();

			int total = numH * numW;
			int col = h * numW;
			int row = w * (numH - h);
			System.out.println(total - col - row);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveB() {
		Scanner scanner = null;
		int numN = 0;
		int numM = 0;
		int numC = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();
			numM = scanner.nextInt();
			numC = scanner.nextInt();
			int[] bArray = new int[numM];
			int[][] aArray = new int[numN][numM];

			for (int i = 0; i < bArray.length; i++) {
				bArray[i] = scanner.nextInt();

			}
			for (int i = 0; i < aArray.length; i++) {
				for (int j = 0; j < aArray[i].length; j++) {
					aArray[i][j] = scanner.nextInt();
				}
			}
			int cnt = 0;

			for (int i = 0; i < aArray.length; i++) {
				int res = 0;
				for (int j = 0; j < aArray[i].length; j++) {
					res += (aArray[i][j] * bArray[j]);
				}
				if (res + numC > 0) {
					cnt++;
				}
			}

			System.out.println(cnt);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	private void solveC() {
		Scanner scanner = null;
		int numN = 0;
		long numM = 0;

		try {
			scanner = new Scanner(System.in);
			numN = scanner.nextInt();
			numM = scanner.nextLong();

			Long[][] wk = new Long[numN][2];

			for (int i = 0; i < numN; i++) {
				wk[i][0] = scanner.nextLong();
				wk[i][1] = scanner.nextLong();
			}

			Arrays.sort(wk, new LComp());

			long resNumM = numM;
			long res = 0;
			for (int i = 0; i < wk.length; i++) {
				if (resNumM <= 0) {
					break;
				}
				long key = wk[i][0];
				long value = wk[i][1];
				if (resNumM >= value) {
					res += (key * value);
					resNumM -= value;
				} else {
					res += (key * resNumM);
					resNumM = 0;
				}

			}

			System.out.println(res);

		} finally {
			if (scanner != null) {
				scanner.close();
			}
		}
	}

	public static class LComp implements Comparator<Long[]> {

		@Override
		public int compare(Long[] o1, Long[] o2) {
			return Long.compare(o1[0], o2[0]);
		}

	}

	private long calcD3(long num) {
		if (num <= 0) {
			return 0;
		}
		/*
		 * 4????0,1,2,3,4???????????5??????
		 * ??????????1???????
		 */
		num++;
		/*
		 * 10^3 <= 2^10
		 * 1000 <= 1024
		 * 10^12 <= 2?? 40????
		 */

		long res = 0;

		//i?????????
		for (int i = 0; i < 50; i++) {
			/*
			 * 0?????1?????? 2
			 * 1                                       4
			 * 2                                       8
			 */
			long loop = ((long) 1 << (long) (i + 1));
			long cnt = (num / loop) * (loop / 2);
			//00000.....0011111.....11
			cnt += Math.max(0, (num % loop) - (loop / 2));
			//????1????????????
			if (cnt % 2 == 1) {
				res += (long) 1 << i;
			}
		}
		return res;
	}

	private void solveD() {
		long numA = 0;
		long numB = 0;

		try (Scanner scanner = new Scanner(System.in)) {
			numA = scanner.nextLong();
			numB = scanner.nextLong();
			System.out.println();
		}
	}

	private void solveD3() {
		long numA = 0;
		long numB = 0;

		try (Scanner scanner = new Scanner(System.in)) {
			numA = scanner.nextLong();
			numB = scanner.nextLong();
			long res = calcD3(numB) ^ calcD3(numA - 1);
			System.out.println(res);
		}
	}

	private void solveD2() {
		long numA = 0;
		long numB = 0;

		try (Scanner scanner = new Scanner(System.in)) {
			numA = scanner.nextLong();
			numB = scanner.nextLong();
			if (numA == numB) {
				System.out.println(numA);
				return;
			}

			long start = numA + 1;
			long res = numA;
			while (true) {
				res = res ^ start;
				start++;
				if (start > numB) {
					break;
				}
			}

			System.out.println(res);

		}
	}
}