import java.util.Scanner;

public class Main{
	final static int MAX_VALUE=100001;
	public static void main( String[] args ) {


		Scanner scan = new Scanner( System.in );
		int R = scan.nextInt();
		int C = scan.nextInt();
		int K = scan.nextInt();
		int N = scan.nextInt();

		int[] r = new int[N];
		int[] c = new int[N];
		int[] sum_r = new int[R];
		int[] sum_c = new int[C];

		for( int i = 0; i < N; i++){
			r[i] = scan.nextInt() - 1;
			c[i] = scan.nextInt() - 1;
			sum_r[r[i]]++;
			sum_c[c[i]]++;
		}

		long[] row = new long[MAX_VALUE];
		long[] column = new long[MAX_VALUE];

		for( int i = 0; i < R; i++ ){
			row[sum_r[i]]++;
		}
		for( int i = 0; i < C; i++ ){
			column[sum_c[i]]++;
		}

		long ans = 0;
		for( int i = 0; i <= K; i++){
			ans += row[i] * column[ K - i ];
		}
		for( int i = 0; i < N; i++){
			if( sum_r[r[i]] + sum_c[c[i]] == K ){
				ans--;
			} else if( sum_r[r[i]] + sum_c[c[i]] == K + 1 ){
				ans++;
			}
		}
		System.out.println( ans );
	}
}