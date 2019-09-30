import java.io.File;
import java.io.IOException;
import java.util.*;
 
public class Main {
 
	public static void main(String[] args) throws IOException {
		//File file = new File("input.txt");
		//Scanner sc = new Scanner(file);
		
		Scanner sc = new Scanner(System.in);
		
		int ans = 0;
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[][] uv = new int[2 * M][2];
		for(int i = 0; i < M; i++){
			int u = sc.nextInt();
			int v = sc.nextInt();
			int[] edge = {u, v};
			uv[i] = edge;
			int[] edge2 = {v, u};
			uv[i + M] = edge2;
		}
		
		ArrayList<Integer[]> queue = new ArrayList<Integer[]>();
		int[] check = new int[N+1];
		int checkNum = 0;
		
		for(int nodeNum = 1; nodeNum <= N; nodeNum++){
			//System.out.println(":" + nodeNum);
			if(check[nodeNum] != 0) continue;
			
			boolean tf = true;
			
			checkNum = nodeNum;
			check[nodeNum] = checkNum;
			for(int i = 0; i < 2 * M; i++){
				if(uv[i][0] == nodeNum){
					Integer[] q = {uv[i][1], nodeNum};
					queue.add(q);
					check[uv[i][1]] = checkNum;
					//System.out.println("add " + uv[i][1]);
				}
			}
			
			while(queue.size() != 0){
				Integer[] q = queue.remove(0);
				//System.out.println("remove " + q[0]);
				for(int i = 0; i < 2 * M; i++){
					if(uv[i][0] == q[0] && uv[i][1] != q[1]){
						if(check[uv[i][1]] != 0) tf = false;
						else{
							check[uv[i][1]] = checkNum;
							Integer[] qq = {uv[i][1], q[0]};
							queue.add(qq);
							//System.out.println("add " + uv[i][1]);
						}
					}
				}
			}
			
			if(tf) ans++;
			
			/*
			for(int i = 1; i <= N; i++){
				System.out.print(check[i]);
			}
			System.out.println("\n" + ans);
			*/
			
		}
		
		System.out.println(ans);
	}
}