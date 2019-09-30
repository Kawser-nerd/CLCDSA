import java.util.ArrayList;
import java.util.Scanner;

public class Main {


	static int dp[][][];
	static int man;
	static int M;

	static int[][] happy;
	static int[] keta;

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner scan=new Scanner(System.in);

		int N=scan.nextInt();
		M=scan.nextInt();
		int P=scan.nextInt();
		int Q=scan.nextInt();
		int R=scan.nextInt();



		//?M?????Q????????
		int two =1;
		keta=new int[M];

		for(int i=0;i<M;i++){
			keta[i]=two;//keta[i]??????1?i+1???1
			two*=2;
		}
		ArrayList<Integer> men =new ArrayList<Integer>();
		for(int i=0;i<two;i++){
			if(Integer.bitCount(i)==Q){
				men.add(i);
			}
		}
		dp = new int[N+1][P+1][men.size()];

		happy = new int[N][M];
		for(int i=0;i<R;i++){
			int x=scan.nextInt()-1;
			int y=scan.nextInt()-1;
			happy[x][y]=scan.nextInt();
		}


		//???man??????????dp???????dp[N][P]???
		int max=0;
		for(int i=0;i<men.size();i++){
			man=men.get(i);

			//System.out.println(sigma(man,0));

			max=Math.max(max, res(N,P,i));
			}

		System.out.println(max);





	}


	static int res(int i,int p,int k){
		if(i==0){
			return 0;
		}
		if(dp[i][p][k]>0){
			return dp[i][p][k];
		}

		if(p>0){
			dp[i][p][k]=Math.max(res(i-1,p,k), res(i-1,p-1,k)+sigma(man,i-1));
		}else{
			dp[i][p][k]=res(i-1,p,k);
		}
		return dp[i][p][k];

	}

	static int sigma(int man,int m){
		//??????m?????man????
		int happiness=0;
		for(int i=0;i<M;i++){
/*			System.out.println(keta[i]);
			System.out.println(man);
			System.out.println();
			System.out.println((keta[i]&man));*/
			if(Integer.bitCount(keta[i]&man)==1){
				happiness+=happy[m][i];
			}
		}
		return happiness;


	}

}