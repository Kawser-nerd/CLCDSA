import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		final long MOD = 1000000007;
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		if(Math.abs(N-M)>1) {
			System.out.println(0);
		} else {
			long ans = 1;
			for(int i=2; i<=N; i++)
				ans = (ans * i)%MOD;
			for(int i=2; i<=M; i++)
				ans = (ans * i)%MOD;
			if(N==M)
				ans = (ans * 2)%MOD;
			
			System.out.println(ans);
		}
		sc.close();
	}
}