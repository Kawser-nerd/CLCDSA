import java.util.Arrays;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		// ?????
		int ans=0;
		int N = Integer.parseInt(sc.next());
		int M = Integer.parseInt(sc.next());
		int[][] relation = new int[N][N];
		for(int i=0; i<M; i++){
			int x = Integer.parseInt(sc.next());
			int y = Integer.parseInt(sc.next());
			relation[x-1][y-1] = 1;
			relation[y-1][x-1] = 1;
		}
		for(int i=0; i<N; i++){
			relation[i][i] = 1;
		}
		for(int i=0; i<(1<<N); i++){
			boolean flag = true;
			int member = 0;
			for(int j=0; j<N; j++){
				if(!flag)break;
				if(((i>>j)&1) == 1){
					for(int k=0; k<N; k++){
						if(j==k)continue;
						if(((i>>k)&1)==0){
							continue;
						}
						if(((i>>k)&1)==1){
							if(relation[k][j]!=1){
								flag = false;
								break;
							}			
						}
					}
					member++;
				}
			}
			if(flag && ans < member)ans = member;
		}
		System.out.println(ans);
		sc.close();
	}
}