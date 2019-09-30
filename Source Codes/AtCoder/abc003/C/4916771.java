import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] R = new int[N];
		for(int i = 0; i < N; i++)
			R[i] = sc.nextInt();
		Arrays.sort(R);
		double rate = 0;
		for(int i = N - K; i < N; i++)
			rate = (rate + R[i]) / 2D;
		System.out.println(rate);
	}

}