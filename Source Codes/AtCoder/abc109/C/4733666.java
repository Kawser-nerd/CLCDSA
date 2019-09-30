import java.util.Scanner;
public class Main {
	
	public static int gcd(int a, int b) {
		if(b == 0)
			return a;
		else
			return gcd(b, a % b);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int X = sc.nextInt();
		int[] x = new int[N];
		x[0] = sc.nextInt();
		int ans = Math.abs(x[0]-X);
		for(int i = 1; i < N; i++) {
			x[i] = sc.nextInt();
			ans = gcd(Math.abs(x[i]-X), ans);
		}
		System.out.println(ans);
	}

}