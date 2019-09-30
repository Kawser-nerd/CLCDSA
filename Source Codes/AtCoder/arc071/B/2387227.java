import java.util.Scanner;

public class Main {

	static int MOD = 1000000007;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		long xSum = 0;
		long ySum = 0;
		for (int i=0;i<n;i++) {
			xSum = (xSum + (2*i-n+1)*sc.nextLong())%MOD;
		}
		for (int i=0;i<m;i++) {
			ySum = (ySum + (2*i-m+1)*sc.nextLong())%MOD;
		}

		System.out.println((((xSum * ySum) % MOD)+MOD)%MOD);
	}

}