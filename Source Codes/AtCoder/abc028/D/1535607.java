import java.util.Scanner;

/**
 * http://abc028.contest.atcoder.jp/tasks/abc028_d
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		final int K = sc.nextInt();
		sc.close();
		
		double l = (double)(K-1)/(double)N;
		double m = (double)1/(double)N;
		double u = (double)(N-K)/(double)N;
		
		double ans = l*m*u*6 + m*m*u*3 + m*m*l*3 + m*m*m;
		
		System.out.println(ans);

	}

}