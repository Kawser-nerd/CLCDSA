import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		solveA();
		//		solveB();
		//		solveC();
		//		solveC2();
		//		solveD();
		//		solveD2();
	}

	private static void solveA() {

		try (Scanner scanner = new Scanner(System.in)) {
			String numT = "";
			String numX = "";

			numT = scanner.next();
			numX = scanner.next();

			BigDecimal result = new BigDecimal(numT).divide(
					new BigDecimal(numX), 6, RoundingMode.HALF_UP);
			System.out.println(result.floatValue());

		}
	}

	private static void solveB() {

		try (Scanner scanner = new Scanner(System.in)) {
			int numN = 0;
			numN = scanner.nextInt();
			int[] wkArray = new int[numN];
			for (int i = 0; i < numN; i++) {
				wkArray[i] = scanner.nextInt();
			}

			Arrays.sort(wkArray);

			int max = 0;
			int others = 0;
			for (int i = numN - 1; i >= 0; i--) {
				if (i == numN - 1) {
					max = wkArray[i];
				} else {
					others += wkArray[i];
				}

			}
			System.out.println(max < others ? "Yes" : "No");

		}
	}

	private static void solveC() {

		try (Scanner scanner = new Scanner(System.in)) {
			int numN = 0;
			int numM = 0;
			numN = scanner.nextInt();
			numM = scanner.nextInt();
			if (numM == 1 && numN >= numM) {
				System.out.println(0);
				return;
			}
			int[] distArray = new int[numM];
			for (int i = 0; i < numM; i++) {
				distArray[i] = scanner.nextInt();
			}

			Arrays.sort(distArray);

			int moveDist = Math
					.abs((distArray[distArray.length - 1] - distArray[0])
							/ numN);

			int[] komaArray = new int[numN];

			int distTime = 0;
			int prevKomaNo = 0;
			for (int i = 0; i < distArray.length; i++) {
				if (i == 0) {
					komaArray[distTime] = distArray[i];
					prevKomaNo = distTime;
					distTime++;
					continue;
				}
				int distance = moveDist * distTime;
				if (distArray[komaArray[prevKomaNo]] + distance > distArray[i]) {
					komaArray[distTime] = distArray[i];
					prevKomaNo = distTime;
					distTime++;
					continue;
				}
				if (i == distArray.length - 1) {
					komaArray[komaArray.length - 1] = distArray[i];
				}
			}

		}
	}

	private static void solveC2() {

		try (Scanner scanner = new Scanner(System.in)) {
			int numN = 0;
			int numM = 0;
			numN = scanner.nextInt();
			numM = scanner.nextInt();
			if (numM == 1 && numN >= numM) {
				System.out.println(0);
				return;
			}
			int[] distArray = new int[numM];
			for (int i = 0; i < numM; i++) {
				distArray[i] = scanner.nextInt();
			}

			Arrays.sort(distArray);
			int[] sabunArray = new int[distArray.length - 1];

			for (int i = 0; i < sabunArray.length; i++) {
				sabunArray[i] = distArray[i + 1] - distArray[i];
			}

			Arrays.sort(sabunArray);

			int result = 0;
			for (int i = 0; i < numM - numN; i++) {
				result += sabunArray[i];
			}

			System.out.println(result);

		}
	}

	private static void solveD2() {

		try (Scanner scanner = new Scanner(System.in)) {
			long numN = 0;
			long numK = 0;
			numN = scanner.nextLong();
			numK = scanner.nextLong();

			List<Long> wkArray = new ArrayList<Long>();
			for (int i = 0; i < numN; i++) {
				wkArray.add(scanner.nextLong());
			}
			long f = 0;
			List<Long> resultArray = new ArrayList<Long>();
			if (numK == 0) {
				f = calcF(wkArray, f, resultArray, 0);
			} else {
				for (int i = 0; i < numK; i++) {
					f = calcF(wkArray, f, resultArray, i);
				}
			}

			Collections.sort(resultArray);
			System.out.println(resultArray.get(resultArray.size() - 1));

		}
	}

	private static void solveD() {

		try (Scanner scanner = new Scanner(System.in)) {
			long numN = 0;
			long numK = 0;
			numN = scanner.nextLong();
			numK = scanner.nextLong();

			List<Long> wkArray = new ArrayList<Long>();
			for (int i = 0; i < numN; i++) {
				wkArray.add(scanner.nextLong());
			}
			long f = 0;
			List<Long> resultArray = new ArrayList<Long>();
			if (numK == 0) {
				f = calcF(wkArray, f, resultArray, 0);
			} else {
				for (int i = 0; i < numK; i++) {
					f = calcF(wkArray, f, resultArray, i);
				}
			}

			Collections.sort(resultArray);
			System.out.println(resultArray.get(resultArray.size() - 1));

		}
	}

	private static long calcF(List<Long> wkArray, long f,
			List<Long> resultArray, int i) {
		for (int j = 0; j < wkArray.size(); j++) {
			f += i ^ wkArray.get(j);
		}
		resultArray.add(f);
		f = 0;
		return f;
	}
}