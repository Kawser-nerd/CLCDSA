import java.util.Scanner;
	

public class Main{
	static int N;
	static int[][] G;
	static int[] match;
	static Boolean[] used;
	
	public static void main(String args[])throws Exception{
		
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		G = new int[2*N+1][2*N+1];
		match = new int[2*N+1];
		used = new Boolean[2*N+1];
		int[] R = new int[2*N+1];
		int[] B = new int[2*N+1];
		for(int i=0;i<N;i++){
			int a = sc.nextInt()+1;
			int b = sc.nextInt()+1;
			R[a] = b;
		}
		for(int i=0;i<N;i++){
			int c = sc.nextInt()+1;
			int d = sc.nextInt()+1;
			B[c] = d;
		}
		for(int i=0;i<2*N;i++){
			for(int j=i+1;j<=2*N;j++){
				
				if(R[i]>0&&R[i]<B[j]){
					G[i][j]=1;
					G[j][i]=1;
				}
			}
		}
		
		int ans = 0;
		
		for(int v=1;v<=2*N;v++){
			if(match[v]<=0){
				for(int i=1;i<=2*N;i++){
					used[i] = false;
				}

				if(dfs(v)){
					ans++;
				}
			}
		}
		
		System.out.println(ans);
		
	}

	static boolean dfs(int v) {
		used[v] = true;
		for(int i=1;i<=2*N;i++){
		
			if(G[v][i]==1){
				int u = i;
				int w = match[u];
			
				if(w<=0||!used[w]&&dfs(w)){
					match[u]=v;
					match[v]=u;
					return true;
				}
			}
		}
		return false;
	}

	
	
}