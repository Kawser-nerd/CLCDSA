import java.util.Scanner;

public class Main {
	static long N;
	static long ans;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N=sc.nextInt();
		int K=sc.nextInt();
		for(int i=0;i<N;i++) {
			int l=sc.nextInt();
			ans=ans+Math.min(Math.abs(l-K), l);
		}
		System.out.println(ans*2);
	}
}