import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		long N = scn.nextLong();
		int ans = 0;
		long A = 1;
		for(long i = (long)Math.sqrt(N);i > 0;i--) {
			if(N%i==0) {
				A = N/i;
				break;
			}
		}

		while(A >0) {
			ans++;
			A/=10;
		}
		System.out.println(ans);
	}

}