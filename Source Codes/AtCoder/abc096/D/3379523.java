import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = Integer.parseInt(in.nextLine());
		in.close();
		int MAX = 55555;
		boolean[] isPrime = new boolean[MAX + 1];
		Arrays.fill(isPrime, true);
		isPrime[0] = false;
		isPrime[1] = false;
		primeDetection(isPrime);

		boolean[] valid = new boolean[MAX + 1];

		int count = 0;
		for (int i = 2; i < isPrime.length; ++i) {
			if (isPrime[i] && i % 5 == 1) {
				System.out.print(i + " ");
				count++;
			}
			if (count >= N) {
				break;
			}
		}
		System.out.println("");
	}

	private static void primeDetection(boolean[] isPrime) {
		for (int i = 2; i < isPrime.length; ++i) {
			if (!isPrime[i]) {
				continue;
			}
			for (int j = i * 2; j < isPrime.length; j = j + i) {
				isPrime[j] = false;
			}
		}
	}
}