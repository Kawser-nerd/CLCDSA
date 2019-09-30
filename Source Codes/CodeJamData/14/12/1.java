import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

public class FullBinaryTree {
	public static int ans;
	public static int tans;
	public static boolean[] vis;
	public static ArrayList<Integer>[] adj;
	public static void main(String[]Args) throws FileNotFoundException{
		Scanner sc = new Scanner(new File("B-large (2).in"));
		PrintWriter out = new PrintWriter(new File("things.out"));
//		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt(),cc=0;
		while(t-->0){
			int n = sc.nextInt();
			adj = new ArrayList[n];
			for(int k = 0; k < n;k++)
				adj[k] = new ArrayList<Integer>();
			for(int k = 0; k < n-1; k++){
				int a = sc.nextInt()-1;
				int b = sc.nextInt()-1;
				adj[a].add(b);
				adj[b].add(a);
			}
			vis = new boolean[n];
			ans = n;
			for(int k = 0; k < n;k++){
				Arrays.fill(vis, false);
				ans =Math.min(n - dfs(k), ans);
			}
				
			out.printf("Case #%d: %d%n",++cc, ans);
			
		}
		out.close();
	}

	private static int dfs(int k) {
		vis[k]= true;
		ArrayList<Integer> al = new ArrayList<Integer>();
		for(Integer i : adj[k])
			if(!vis[i])
				al.add(dfs(i));
		if(al.size() < 2)
			return 1;
		Collections.sort(al);
		return 1 + al.get(al.size()-1) + al.get(al.size()-2);
	}

	private static long make(String s) {
		return Long.parseLong(s, 2);
	}
}
