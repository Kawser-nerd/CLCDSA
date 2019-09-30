import java.util.Arrays;
import java.util.Scanner;

/**
 * http://abc018.contest.atcoder.jp/tasks/abc018_4
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		final int M = sc.nextInt();
		final int P = sc.nextInt();
		final int Q = sc.nextInt();
		final int R = sc.nextInt();
		int[] x = new int[R];
		int[] y = new int[R];
		int[] z = new int[R];
		for(int i=0; i<R; i++){
			x[i] = sc.nextInt()-1;
			y[i] = sc.nextInt()-1;
			z[i] = sc.nextInt();
		}
		sc.close();
		
		int max = (int) Math.pow(2,N);
		int ans = 0;
		for(int i=1; i<(int) Math.pow(2,N); i++){
			String comb = Integer.toBinaryString(i);
			int count = 0;
			while(comb.length()<N) comb = "0"+comb;
			for(int j=0; j<N; j++) 
				if(comb.charAt(j)=='1') count++;
			if(count==P){
				int[] boy = new int[M];
				for(int j=0; j<R; j++){
					if(comb.charAt(x[j])=='1') boy[y[j]] += z[j];
				}
				Arrays.sort(boy);
				int tmp = 0;
				for(int j=M-1; j>=M-Q; j--)
					tmp += boy[j];
				ans = Math.max(tmp, ans);
			}
		}
		
		System.out.println(ans);

	}

}