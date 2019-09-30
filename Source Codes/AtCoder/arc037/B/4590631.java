import java.util.Arrays;
import java.util.Scanner;


public class Main {
	
	static int N;
	static int M;
	static boolean[] flag;
	static int ans=0;
	static boolean flag_tmp;
	static int[][] G ;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		// ?????
		N = Integer.parseInt(sc.next());
		M = Integer.parseInt(sc.next());
		G = new int[N][N];
		flag = new boolean[N];
		Arrays.fill(flag, false);		//false:???
		for(int i=0; i<M; i++){
			int u = Integer.parseInt(sc.next());
			int v = Integer.parseInt(sc.next());
			G[u-1][v-1] = 1;
			G[v-1][u-1] = 1;
		}
		
		for(int i=0; i<N; i++){
			if(!flag[i]){
				flag_tmp = true;
				walk(i);
				if(flag_tmp)ans++;
			}
		}
		System.out.println(ans);
		sc.close();
	}
	
	public static void walk(int from){
		if(flag[from]){
			flag_tmp = false;
			return;
		}
		flag[from] = true;
		for(int to=0; to<N; to++){
			if(G[from][to]==1){
				G[from][to]=0;
				G[to][from]=0;
				walk(to);
			}
		}
		
	}
	
}