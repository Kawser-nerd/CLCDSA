import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int M=sc.nextInt();
		int[][] kankeigraph=new int[N+1][N+1];
		int[] friend=new int[10];
		boolean[] friend_of_friend=new boolean[11];
		int friend_cnt=0;
		for(int i=0; i<=N; i++) {
			for(int j=0; j<=N; j++) {
				kankeigraph[i][j]=0;
			}
		}

		for(int i=0; i<10; i++) {
			friend[i]=0;
		}

		for(int i=0; i<M; i++) {
			int from=sc.nextInt();
			int to=sc.nextInt();
			kankeigraph[from][to]=1;
			kankeigraph[to][from]=1;
		}

		for(int i=1; i<=N; i++) {
			for(int j=0; j<10; j++) {
				friend[j]=0;
			}
			for(int j=1; j<=10; j++) {
				friend_of_friend[j]=false;
			}
			friend_cnt=0;
			for(int j=1; j<=N; j++) {
				if(kankeigraph[i][j]==1) {
					friend[friend_cnt]=j;		//?????
					friend_cnt++;
				}
			}
			for(int j=0; j<friend_cnt; j++) {
				for(int k=1; k<=N; k++) {
					if(kankeigraph[friend[j]][k]==1 && kankeigraph[i][k]==0 && i!=k) {			//???????
						friend_of_friend[k]=true;
					}
				}
			}
			int kazu=0;
			for(int j=1; j<=N; j++) {
				if(friend_of_friend[j]) {
					kazu++;
				}
			}
			System.out.println(kazu);
		}
	}
}