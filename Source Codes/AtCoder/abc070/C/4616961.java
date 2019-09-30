import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt();
		long ans = 1;
		for(int i = 0;i < N;i++) {
			ans = solve(ans,scn.nextLong());
		}
		System.out.println(ans);
	}

	public static long solve(long a, long b) {
		long A = Math.max(a, b), B = Math.min(a, b);
		while(A%B !=0) {
			long buf = A%B;
			A = B;
			B = buf;
		}
		return a/B*b;
	}
}