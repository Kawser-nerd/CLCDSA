import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt();
		long[] A = new long[N];
		for(int i = 0;i < N;i++) {
			A[i] = scn.nextLong();
		}
		Arrays.sort(A);
		int ans = 0;
		int count = 0;
		long buf = 0;
		for(int i = 0;i < N;i++) {
			if(buf == A[i]) {
				count++;
			}else {
				if(count%2==1 && count!=0) {
					ans++;
				}
				count = 1;
				buf = A[i];
			}
		}
		if(count%2==1) {
			ans++;
		}

		System.out.println(ans);
	}

}