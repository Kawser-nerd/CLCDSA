import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.Queue;
import java.util.Scanner;


public class Main {
	static int[][] map;
	static boolean[] flag;
	static int N;
	static int ans = 0;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		N = Integer.parseInt(sc.next());
		int M = Integer.parseInt(sc.next());
		map = new int[N][N];
		
		flag = new boolean[N];
		Arrays.fill(flag, true); //true:??????
		
		for(int i=0; i<M; i++){
			int a = Integer.parseInt(sc.next())-1;
			int b = Integer.parseInt(sc.next())-1;
			map[a][b] = 1;
			map[b][a] = 1;
		}
		
		flag[0]=false;
		walk(0,0);
		
		System.out.println(ans);
		
		sc.close();
	}

	public static void walk(int pos, int walked){

		for(int i=0; i<N; i++){
			if(map[pos][i] == 1 && flag[i]){
				walked++;
				if(walked == N-1){
					ans++;
					return;
				}
				flag[i] = false;
				//System.out.println("from:"+pos+" to:"+i+" walked:"+walked);
				walk(i, walked);
				walked--;
				flag[i] = true;
			}
		}
		return;
	}
	
}