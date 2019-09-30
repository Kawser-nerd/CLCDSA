import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner (System.in);
		long Q = sc.nextInt();
		long H = sc.nextInt();
		long S = sc.nextInt();
		long D = sc.nextInt();
		long N = sc.nextInt();
		H = Math.min(Q*2,H);
		S = Math.min(H*2,S);
		D = Math.min(S*2,D);
		if(N%2==0) {
			System.out.println(N/2*D);
		}else {
			System.out.println(N/2*D + S);
		}
	}
}