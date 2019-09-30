import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;

public class ProperShuffle {
	public static int ans;
	public static int tans;
	public static boolean[] vis;
	public static ArrayList<Integer>[] adj;
	public static int n = 1000;
	public static void main(String[]Args) throws FileNotFoundException{

		double[][] GprobsYo = new double[n][n];
		double[][] BprobsYo = new double[n][n];
		for(int k = 0; k < n;k++){
			BprobsYo[k][k] = 1;
		}
		for(int k = 0; k < n;k++){
			for (int j = 0; j < n;j++)if(j != k)
				for (int i = 0; i < n;i++){
					BprobsYo[j][i] = ((n-1) * BprobsYo[j][i] / n) + (BprobsYo[k][i] / n);
				}
			for (int j = 0; j < n;j++){
				BprobsYo[k][j] = 1.0 / n;
			}
			
		}
		for(int k = 0; k < n; k++)
			for(int j = 0; j < n; j++)
				GprobsYo[k][j] = -Math.log(n);
//		for(int k =0; k< n;k++){
//			double sum = 0;
//			for(int j =0; j< n;j++){
//				sum += BprobsYo[k][j];
//				System.out.print(BprobsYo[k][j]+" ");
//			}
//			System.out.println();
//			System.out.println(sum);
//		}
		System.out.println("DONE");
		Scanner sc = new Scanner(new File("C-small-attempt1 (1).in"));
		PrintWriter out = new PrintWriter(new File("things.out"));
//		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt(),cc=0;
		Random r = new Random(1337);
		while(t-->0){
			sc.nextInt();
			double odds = 0;
			int[] things = new int[n];
			for(int k = 0; k < n; k++){
				things[k] =sc.nextInt();
			}
			for(int k = 0; k < n;k++){
				odds += GprobsYo[k][things[k]];
				odds -= Math.log(BprobsYo[k][things[k]]);
//				System.out.println(" "+GprobsYo[k][things[k]] +" "+Math.log(BprobsYo[k][things[k]]));
				
			}
//			System.out.println(cc +" "+odds);
			double Sample = r.nextDouble();
			Sample = f(Sample);
			if(odds < Sample)
				out.printf("Case #%d: BAD%n",++cc, ans);
			else
				out.printf("Case #%d: GOOD%n",++cc, ans);
			
		}
		out.close();
	}

	private static double f(double sample) {
		return Math.atan((sample * Math.PI) - (Math.PI / 2));
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
