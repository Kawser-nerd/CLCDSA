import java.util.Arrays;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		 int N=sc.nextInt();
		int K=sc.nextInt();
		double C=0;
		int rate[]=new int[N];
		for(int i=0;i<N;i++) {
			rate[i]=sc.nextInt();
		}
		Arrays.sort(rate);
		for(int i=N-K;i<N;i++) {
			C=(rate[i]+C)/2;
		}
		System.out.println(C);
	}

}