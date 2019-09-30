import java.util.Scanner;

class Main{
	public static void main(String arg[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		sc.close();
		int ans = K;
		for(int i = 1; i < N; i++ ) {
			ans *= (K-1);	
		}
		System.out.println(ans);
	}
}