import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class FullBinaryTree {
	static final String fileName = "B-large";
	
	FullBinaryTree(){
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		for(int t = 1; t<=tests; t++){
			int N = in.nextInt();
			adj = new ArrayList[N];
			for(int i = 0; i<N; i++)
				adj[i] = new ArrayList<Integer>();
			count = new int[N][N];
			minCut = new int[N][N];
			for(int[] a: minCut)
				Arrays.fill(a, -1);
			for(int[] a: count)
				Arrays.fill(a, -1);
			for(int i = 0; i<N-1; i++){
				int a = in.nextInt()-1;
				int b = in.nextInt()-1;
				adj[a].add(b);
				adj[b].add(a);
			}
			int min = 987654321;
			for(int n = 0; n<N; n++){
				int res;
				if(adj[n].size() == 0)
					res = 0;
				else if(adj[n].size() == 1)
					res = N-1;
				else{
					res = N;
					int sum = count(n, n)-1;
					for(int i = 0; i<adj[n].size(); i++){
						for(int j = i+1; j<adj[n].size(); j++){
							res = Math.min(res, minCut(adj[n].get(i), n)+minCut(adj[n].get(j), n) + 
									sum - (count(adj[n].get(i), n)+count(adj[n].get(j), n)));
						}
					}
				}
				min = Math.min(res, min);
			}
			System.out.printf("Case #%d: %d\n", t, min);
		}
		in.close();
	}
	ArrayList<Integer>[] adj;
	
	int[][] minCut;
	int minCut(int n, int prev){
		if(minCut[n][prev] != -1)
			return minCut[n][prev];
		int res = 0;
		if(adj[n].size() <= 1){
			res = 0;
		}else if(adj[n].size() == 2){
			int longBranch = (adj[n].get(0) == prev ? adj[n].get(1) : adj[n].get(0));
			res = count(longBranch, n);
		}else{
			int min = 987654321;
			int sum = count(n, prev)-1;
			for(int i = 0; i<adj[n].size(); i++){
				if(adj[n].get(i) == prev)
					continue;
				for(int j = i+1; j<adj[n].size(); j++){
					if(adj[n].get(j) == prev)
						continue;
					min = Math.min(min, minCut(adj[n].get(i), n)+minCut(adj[n].get(j), n) + 
							sum - (count(adj[n].get(i), n)+count(adj[n].get(j), n)));
				}
			}
			res = min;
		}
		return minCut[n][prev] = res;
	}
	
	int[][] count;
	int count(int n, int prev){
		if(count[n][prev] != -1)
			return count[n][prev];
		int res = 1;
		for(int i : adj[n]){
			if(i == prev)
				continue;
			res += count(i, n);
		}
		return count[n][prev] = res;
	}
	public static void main(String[] args) throws Exception{
		String root = "C:/Users/Tyler/Downloads/";
		String file = FullBinaryTree.fileName;
		System.setIn(new FileInputStream(new File(root+file+".in")));
		System.setOut(new PrintStream(new File(root+file+".out")));
		new FullBinaryTree();
	}
}
