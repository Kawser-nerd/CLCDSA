import java.util.LinkedList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner scan = new Scanner(System.in);
		int H = scan.nextInt();
		int W = scan.nextInt();
		int K = scan.nextInt();

		int[] dix ={-1,0,1,0};
		int[] diy ={0,1,0,-1};


		final int INF = 100000;

		LinkedList<Integer> nexti = new LinkedList<Integer>();
		LinkedList<Integer> nextj = new LinkedList<Integer>();

		int[][] A = new int[H][W];

		for(int i=0;i<H;i++){
			String S=scan.next();
			for(int j=0;j<W;j++){
				String s = S.substring(j,j+1);
				if(s.equals("S")){
					A[i][j]=0;
					nexti.add(i);
					nextj.add(j);
				}else if(s.equals(".")){
					A[i][j]=INF;
				}else{
					A[i][j]=-1;
				}
			}
		}




//MAP???1???????1???
		for(int w=0;w<K;w++){
			int loop = nexti.size();
			for(int cnt=0;cnt<loop;cnt++){
				int i = nexti.poll();
				int j = nextj.poll();//???????i,j

				for(int x=0;x<4;x++){

						if(i+dix[x]>=0&&i+dix[x]<H&&j+diy[x]>=0&&j+diy[x]<W&&A[i+dix[x]][j+diy[x]]==INF){
							A[i+dix[x]][j+diy[x]] = w+1;
							nexti.add(i+dix[x]);
							nextj.add(j+diy[x]);
						}
				}
			}
		}

int min=INF;
//0??K???????????????
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(A[i][j]>=0&&A[i][j]<INF){
					min = Math.min(min, i);
					min = Math.min(min, H-i-1);
					min = Math.min(min, j);
					min = Math.min(min, W-j-1);
				}
			}
			}

		int ans =1+(min+K-1)/K;



		System.out.println(ans);



	}

}