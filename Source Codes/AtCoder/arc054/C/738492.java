import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		new Main().solve();
	}
	void solve(){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[][] S=new int[n][n];
		for(int i=0;i<n;i++){
			char[] c=sc.next().toCharArray();
			for(int j=0;j<n;j++){
				S[i][j]=c[j]-'0';
			}
		}

		//		for(int i=0;i<n;i++){
		//			for(int j=0;j<n;j++){
		//				System.out.print(S[i][j]+" ");
		//			}
		//			System.out.println();
		//		}
		System.out.println(Math.abs(detMt(S)%2)==1?"Odd":"Even");
	}
	int count=1;
	/*???:det(A)
	 * Gaussian Elimination???????????????
	 */
	int detMt(int[][] A){
		assert A.length==A[0].length;
		int n=A.length;
		int det=1;
		for(int i=0;i<n;i++){
			//A[i][i]???j????????????
			
			//A[i][i]?0??????????????
			//???0??????det=0
			if(A[i][i]==0){
				for(int j=i+1;j<n;j++){
					if(A[j][i]!=0){
						for(int k=0;k<n;k++){
							int d=A[i][k];
							A[i][k]=A[j][k];
							A[j][k]=d;
						}
						break;
					}
					if(j==n-1)return 0;
				}
			}
			for(int j=i+1;j<n;j++){
				//A[j][i]?0?????????
				double rate=A[j][i]/A[i][i];
				for(int k=0;k<n;k++){
					A[j][k]+=rate*A[i][k];
					A[j][k]%=2;
				}
			}
		}
		for(int i=0;i<n;i++)det*=A[i][i];
		while(det<0)det++;
		return det;
	}
}