import java.util.Scanner;
import java.util.*;

public class Main {
	public static ArrayList <Integer>linkList[][];
	public static int dists[];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		linkList = new ArrayList[N + 1][2];
		dists = new int[N + 1];
		
		for(int i = 0; i < N + 1; i++) {
			dists[i] = Integer.MIN_VALUE;
			linkList[i][0] = new ArrayList<Integer>();
			linkList[i][1] = new ArrayList<Integer>();
		}
		for(int i = 0; i < M; i++) {
			int l = sc.nextInt();
			int r = sc.nextInt();
			int d = sc.nextInt();
			linkList[l][0].add(r);
			linkList[l][1].add(d);
			linkList[r][0].add(l);
			linkList[r][1].add(-d);
		}
		for(int i = 0; i < N; i++){
			if(dists[i] != Integer.MIN_VALUE)continue;
			if(!dfs(i, 0)){
				System.out.println("No");
				return;
			}
		}
		System.out.println("Yes");
	}
	public static boolean dfs(int i, int dist) {
		if(dists[i] != Integer.MIN_VALUE)return dists[i] == dist;
		dists[i] = dist;
		for(int j = 0; j < linkList[i][0].size(); j++) {
			if(!dfs(linkList[i][0].get(j), dist + linkList[i][1].get(j)))return false;
		}
		return true;
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.