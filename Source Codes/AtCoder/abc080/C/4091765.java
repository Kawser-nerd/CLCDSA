import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().execute();
	}

	public void execute() {
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		int[] F = new int[N];
		int[][] P = new int[N][11];
		sc.nextLine();
		for (int i = 0; i < N; i++) {
			String[] fi = sc.nextLine().split(" ");
			F[i] = getMask(fi);
		}
		for (int i = 0; i < N; i++) {
			String[] pi = sc.nextLine().split(" ");
			for (int j = 0; j < 11; j++) {
				P[i][j] = Integer.parseInt(pi[j]);
			}
		}

		long maxRev = Long.MIN_VALUE;
		for (int mask = 1; mask < 1024; mask++) {
			long rev = 0;
			for (int i = 0; i < N; i++) {
				rev += P[i][countOnes(mask & F[i])];
			}
			maxRev = Math.max(maxRev, rev);
		}
		System.out.println(maxRev);
		sc.close();
	}

	private int getMask(String[] input) {
		int mask = 0;
		for (String s : input) {
			mask = mask * 2;
			if (Integer.parseInt(s) == 1) {
				mask += 1;
			}
		}
		return mask;
	}

	private int countOnes(int mask) {
		int cnt = 0;
		while (mask > 0) {
			if ((mask & 1) == 1) {
				cnt++;
			}
			mask = mask / 2;
		}
		return cnt;
	}
}