import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = Integer.parseInt(scan.next());
		long K = Long.parseLong(scan.next());
		int maxDigit = 40;
		String binK = toBinaryString(K, maxDigit);
		long[] A = new long[N];
		for (int i = 0; i < N; i++) {
			A[i] = Long.parseLong(scan.next());
		}
		String[] binA = new String[N];
		for (int i = 0; i < N; i++) {
			binA[i] = toBinaryString(A[i], maxDigit);
		}
		String binAns;
		int numOfOne;
		int numOfZero;
		long result = Long.MIN_VALUE;
		for (int i = 0; i < maxDigit; i++) {
			binAns = "";
			for (int l = 0; l <= i; l++) {
				if (l != maxDigit - 1 && l == i) {
					binAns += '0';
				} else {
					binAns += binK.charAt(l);
				}
			}

			for (int k = i + 1; k < maxDigit; k++) {
				numOfOne = 0;
				numOfZero = 0;
				for (int j = 0; j < N; j++) {
					if (binA[j].charAt(k) == '1') {
						numOfOne++;
					} else {
						numOfZero++;
					}
				}
				if (numOfZero >= numOfOne) {
					binAns += "1";
				} else {
					binAns += "0";
				}
			}
			if (K >= Long.parseLong(binAns, 2)) {
				result = Math.max(result, function(Long.parseLong(binAns, 2), A));
			}
		}
		System.out.println(result);

	}

	public static long function(long X, long[] A) {
		long sum = 0;
		for (int i = 0; i < A.length; i++) {
			sum += X ^ A[i];
		}
		return sum;
	}

	public static String toBinaryString(long a, int digit) {
		String binString = String.format("%40s", Long.toBinaryString(a));
		binString = binString.replace(' ', '0');
		return binString;
	}
}