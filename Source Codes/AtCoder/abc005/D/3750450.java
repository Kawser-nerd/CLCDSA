import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int[][] tk=new int[N+1][N+1];
		for(int i=0; i<=N; i++) {
			for(int j=0; j<=N; j++) {
				tk[i][j]=0;
			}
		}
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				tk[i+1][j+1]=sc.nextInt();
			}
		}
		//N^2
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				tk[i][j]=tk[i][j-1]+tk[i][j];
			}
		}

		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				tk[j][i]=tk[j-1][i]+tk[j][i];
			}
		}

		/*for(int i=0; i<=N; i++) {
			for(int j=0; j<=N; j++) {
				System.out.print(tk[i][j]+" ");
			}
			System.out.println("");
		}*/
		int tc=sc.nextInt();
		int[][] ippen=new int[20][2];
		for(int i=0; i<20; i++) {
			ippen[i][0]=0;
		}
		int[] max_atai=new int[N*N+1];
		for(int i=0; i<=N*N; i++) {
			max_atai[i]=0;
		}

		int max=0;
		for(int i=1; i<=N*N; i++) {
			ippen=zrk(ippen,i,N);
			if(ippen[0][1]>0) {
				max=0;
				for(int j=0; j<ippen[0][1]; j++) {
					for(int k=1; k<=N-ippen[j][0]+1; k++) {
						for(int l=1; l<=N-(i/ippen[j][0])+1; l++) {
							max=Math.max(max, tk[k+ippen[j][0]-1][l+(i/ippen[j][0])-1]-tk[k+ippen[j][0]-1][l-1]-tk[k-1][l+(i/ippen[j][0])-1]+tk[k-1][l-1]);
						}
					}
					max_atai[i]=max;
				}
				//System.out.println(i+" "+max_atai[i]);
			}
		}
		for(int i=1; i<=N*N; i++) {
			max_atai[i]=Math.max(max_atai[i-1], max_atai[i]);
		}
		for(int i=0; i<tc; i++) {
			System.out.println(max_atai[sc.nextInt()]);
		}
	}

	static int[][] zrk(int[][] ippen, int atai,int N) {//????????????????????MAX
		int tmp=0;
		for(int i=1; i<=atai; i++) {
			if(atai%i==0 && atai/i<=N && i<=N) {
				ippen[tmp][0]=i;
				tmp++;
			}
		}
		ippen[0][1]=tmp;
		return ippen;
	}
}