import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		sc.close();
		int min = 10 * N;
		for(int A = 1; A <= N / 2; A++) {
			int B = N - A;
			min = Math.min(min, digitsSum(A) + digitsSum(B));
		}
		System.out.println(min);
	}
	static int digitsSum(int n) {
		int ret = 0;
		String s = Integer.toString(n);
		for(int i = 0; i < s.length(); i++) {
			ret += Integer.parseInt(s.substring(i, i + 1));
		}
		return ret;
	}
}