import java.util.Scanner;
	

public class Main{
	
	
	public static void main(String args[])throws Exception{
		Scanner sc = new Scanner(System.in);

		int N = sc.nextInt();
		long[][] A = new long[N][N];
		long[][] D = new long[N][N];
		Boolean nes[][] = new Boolean[N][N];
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				A[i][j] = sc.nextLong();
				if(A[i][j]==0&&i!=j){
					A[i][j] = (long) 10e12;
				}
				D[i][j] = A[i][j];
				nes[i][j] = true;
			}
			

		}

		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				for(int k=0;k<N;k++){
					if(j!=i&&k!=i&&D[j][k]==D[j][i]+D[i][k]){

						nes[j][k] = false;
					}
					D[j][k] = Math.min(D[j][k], D[j][i]+D[i][k]);
					
				}
			}
		}
		

		long ans = 0;
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				if(A[i][j]!=D[i][j]){

					System.out.println(-1);
					return;
				}

				if(nes[i][j]){
					ans += D[i][j];
				}
			}
		}
		
		System.out.println(ans);
	}
	

}