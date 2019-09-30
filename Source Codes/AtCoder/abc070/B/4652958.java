import java.util.Scanner;

public class Main {
	static long N;
	static long ans;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N=sc.nextInt();
		int K=sc.nextInt();
		int L=sc.nextInt();
		int M=sc.nextInt();
		int start=Math.max(N, L);
		int end=Math.min(K, M);
		System.out.println(end-start<0?0:end-start);
	}
}