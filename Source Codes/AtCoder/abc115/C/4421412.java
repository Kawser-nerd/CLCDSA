import java.util.Arrays;
import java.util.Scanner;
public class Main {
	static int N,K;
	static int min=1000000000;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N=sc.nextInt();
		K=sc.nextInt();
		int h[]=new int[N];
		for(int i=0;i<N;i++) h[i]=sc.nextInt();
		Arrays.sort(h);
		for(int i=0;i<=N-K;i++) {
			if(min>h[i+K-1]-h[i])min=h[i+K-1]-h[i];
		}
		System.out.println(min);
	}
}