import java.util.Scanner;

class Main{
	public static void main(String arg[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		sc.close();
		
		System.out.println(color(N,K));
	}
	
	public static int color(int N, int K){
		int color = K;
		for (int i = 1; i < N; i++) {
			color *= (K-1);
		}
		return color;
	}
}