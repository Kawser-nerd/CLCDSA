import java.util.Scanner;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// 0.input
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int C = sc.nextInt();
		
		int D[][] = new int[C][C];
		for(int i=0; i<C; i++) {
			for(int j=0; j<C; j++) {
				D[i][j] = sc.nextInt();
			}
		}
		
		int c[][] = new int[N][N];
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				c[i][j] = sc.nextInt();
			}
		}
		
		// 1.Grid???????mod3?0,1,2???????????????????
		int[] mod3_0 = new int[C];
		int[] mod3_1 = new int[C];
		int[] mod3_2 = new int[C];
		
		Arrays.fill(mod3_0, 0);
		Arrays.fill(mod3_1, 0);
		Arrays.fill(mod3_2, 0);
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(((i+1)+(j+1)) % 3 == 0) {
					mod3_0[c[i][j]-1] += 1;
				}
				else if(((i+1)+(j+1)) % 3 == 1) {
					mod3_1[c[i][j]-1] += 1;
				}
				else {
					mod3_2[c[i][j]-1] += 1;
				}
			}
		}
		
		// 2.C^3???????????i=j,j=k,k=i????pass
		int ans = Integer.MAX_VALUE;
		
		for(int col1=0; col1<C; col1++) {
			for(int col2=0; col2<C; col2++) {
				if(col1 == col2) {
					continue;
				}
				for(int col3=0; col3<C; col3++) {
					if(col1 == col3 || col2 == col3) {
						continue;
					}
					
					int ans_temp = 0;
					
					//col1?????
					for(int col=0; col<C; col++) {
						ans_temp += mod3_0[col] * D[col][col1];
						ans_temp += mod3_1[col] * D[col][col2];
						ans_temp += mod3_2[col] * D[col][col3];
					}
					
					ans = Math.min(ans, ans_temp);
					
				}
			}
		}
		
		System.out.println(ans);
		
	}

}