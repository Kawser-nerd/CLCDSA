import java.util.*;

public class B {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt(); in.nextLine();
		for(int cas=1; cas<=T; cas++) {
			int n = in.nextInt();
			int W = in.nextInt();
			int L = in.nextInt();
			int[][] A = new int[n][2];
			for(int i=0; i<n; i++) {
				A[i] = new int[]{in.nextInt(),i};
			}
			int[] C = new int[n];
			for(int i=0; i<n; i++) C[i]=A[i][0];
			Arrays.sort(A, new Comparator<int[]>() {
				public int compare(int[] A, int[] B) {
					return A[0]-B[0];
				}
			});
			int r=0;
			int c=0;
			int next_inc = 0;
			int[][] B = new int[n][2];
			for(int i=n-1; i>=0; i--) {
				B[A[i][1]] = new int[]{c,r};
				if(i==0) break;
				c += 2*A[i][0];
				next_inc = Math.max(next_inc, 2*A[i][0]);
				if(c > W) {
					c = 0;
					r += next_inc;
					next_inc = 0;
				}
			}
			
			for(int i=0; i<n; i++) {
				if(B[i][0] < 0 || B[i][1]<0 || B[i][0]>W || B[i][1]>L) {
					System.out.printf("OFF MAT: %d\n", i);
				}
			}
			for(int i=0; i<n; i++)
				for(int j=i+1; j<n; j++) {
					long dx = B[i][0]-B[j][0];
					long dy = B[i][1]-B[j][1];
					if(Math.sqrt(dx*dx + dy*dy) < C[i]+C[j]) {
						System.out.printf("COLLIDE: %d %d %d %d %f %d\n", i, j, dx, dy, Math.sqrt(dx*dx + dy*dy), C[i]+C[j]);
					}
				}

			System.out.printf("Case #%d:", cas);
			for(int i=0; i<n; i++) {
				System.out.printf(" %d %d", B[i][0], B[i][1]);
			}
			System.out.println();
		}
	}
}