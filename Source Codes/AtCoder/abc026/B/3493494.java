import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] R = new int[N];
		for(int i = 0;i < N;++i)
			R[i] = sc.nextInt();
		sc.close();
		
		Arrays.sort(R);
		int r2 = 0;
		boolean flag = true;
		for(int i = R.length-1;i >= 0;--i) {
			if(flag)
				r2 += R[i] * R[i];
			else
				r2 -= R[i] * R[i];
			flag = !flag;
		}
		System.out.println(r2 * Math.PI);
	}
}