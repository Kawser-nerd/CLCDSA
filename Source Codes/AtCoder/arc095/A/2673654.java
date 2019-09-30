import java.util.Arrays;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] X = new int[N];
		int[] XS = new int[N];
		for(int i=0; i<N; i++) {
			X[i] = sc.nextInt();
			XS[i] = X[i];
		}Arrays.sort(XS);

		for(int j=0; j<N; j++) {
			if(X[j] * 2 > XS[N/2-1] + XS[N/2]) {
				System.out.println(XS[N/2-1]);
			}else {
				System.out.println(XS[N/2]);
			}
		}

	}

}