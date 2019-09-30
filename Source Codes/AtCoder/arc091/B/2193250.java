import java.util.Scanner;

/**
 * https://arc091.contest.atcoder.jp/tasks/arc091_b
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		long K = sc.nextLong();
		sc.close();
		
		long ans = 0;
		
		if(K==0){
			ans = N*N;
		}else{
			for(long b=N; b>0; b--){
				ans+=Math.max(0, (b-K)*(N/b));
				ans+=Math.max(0, N%b-K+1);
			}
		}
		System.out.println(ans);
	}

}