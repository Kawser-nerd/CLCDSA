import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt();
		int[] shop = new int[N];
		for(int i = 0;i < N;i++) {
			int buf = 0;
			for(int j = 0;j <10;j++ ) {
				buf += Math.pow(2, j) * scn.nextInt();
			}
			shop[i] = buf;
		}

		long[][] P = new long[N][11];
		for(int i = 0;i < N;i++) {
			for(int j = 0;j < 11;j++) {
				P[i][j] = scn.nextLong();
			}
		}

		long bene = Long.MIN_VALUE;
		for(int i = 1;i < 1024;i++) {
			long buf = 0;
			for(int j = 0;j < N;j++) {
				int a = (i & shop[j]);
				buf += P[j][count(a)];
			}
			bene = Math.max(bene, buf);
		}
		System.out.println(bene);

	}

	public static int count(int a) {
		int count = 0;
		while(a>0) {
			if(a % 2 == 1)count++;
			a/=2;
		}
		return count;
	}
}