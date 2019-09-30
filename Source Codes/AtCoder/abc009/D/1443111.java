import java.util.Scanner;

/**
 * http://abc009.contest.atcoder.jp/tasks/abc009_4
 */
public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final int K = sc.nextInt();
		final int M = sc.nextInt();
		long[][] a = new long[K][1];
		long[] c = new long[K];
		for(int i=0; i<K; i++) a[K-i-1][0] = sc.nextLong();
		for(int i=0; i<K; i++) c[i] = sc.nextLong();
		sc.close();
		
		long[][] matrix = new long[K][K];
		long[][] current = new long[K][K];
		long[][] result = new long[K][K];
		for(int y=0; y<K; y++){
			for(int x=0; x<K; x++){
				current[y][x] = matrix[y][x] = y== 0 ? c[x] : y-1 == x ? Long.valueOf("8589934591") : 0;
				result[y][x] = x == y ? Long.valueOf("8589934591") : 0;
			}
		}
		
		for( int i=(M-K); i>0; i=i/2){
			if(i%2==1) result = and(result, current);
			current = and(current, current);
		}
		long ans = M <= K ? a[K-M][0] : and(result, a)[0][0];
		System.out.println(ans);
		
	}
	
	private static long[][] and(final long a[][], final long b[][]){
		int h = a.length;
		int w = b[0].length;
		long[][] result = new long[h][w];
		for(int y=0; y<h; y++){
			for(int x=0; x<w; x++){
				for(int i=0; i<a[0].length; i++){
					result[y][x] =  result[y][x] ^ ( a[y][i] & b[i][x] );
				}
			}
		}
		return result;
	}

}