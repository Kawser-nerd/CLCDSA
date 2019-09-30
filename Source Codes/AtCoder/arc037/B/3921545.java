import java.util.*;
public class Main{
	public static void main(String[] argv){
		BaumTest.run();
	}
}

class BaumTest{
	static int n;
	static boolean[] vertex;
	static boolean[][] edge;
	public static void run(){
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		int m = sc.nextInt();
		vertex = new boolean[n];
		edge = new boolean[n][n];
		for(int i=0;i<n;i++){
			vertex[i] = false;
			Arrays.fill(edge[i], false);
		}
		for(int i=0;i<m;i++){
			int u = sc.nextInt()-1;
			int v = sc.nextInt()-1;
			edge[u][v] = edge[v][u] = true;
		}
		int count = 0;
		for(int i=0;i<n;i++){
			if(dfs(i)) {
				count++;
			}
		}
		System.out.println(count);
	}
	
	public static boolean dfs(int v){
		if(vertex[v])
			return false;
		vertex[v] = true;
		for(int i=0;i<n;i++){
			if(edge[v][i]){
				edge[i][v] = false;
				boolean flag = dfs(i);//????????????
				edge[i][v] = true;
				if(!flag)
					return false;
			}
		}
		return true;
	}
}