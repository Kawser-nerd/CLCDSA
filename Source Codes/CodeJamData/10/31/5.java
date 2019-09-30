import java.util.Iterator;
import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		for (int i = 0; i < T; i++) {
			int ans = 0;
			int N =  s.nextInt();
			int W[][] =  new int[N][2];
			for (int j = 0; j < N; j++) {
				W[j][0] =  s.nextInt();
				W[j][1] =  s.nextInt();
			}

			for (int j = 0; j < W.length; j++) {
				for (int j2 = 0; j2 < j; j2++) {
					if(((W[j][0]  > W[j2][0]) && (W[j][1]  < W[j2][1])) || ((W[j][0]  < W[j2][0]) && (W[j][1]  > W[j2][1]))){
						ans++;
					}
				};
			}

			System.out.printf("Case #%d: %d\n", i + 1, ans);
		}
	}

}
