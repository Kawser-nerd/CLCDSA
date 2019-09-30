import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
	
public class Main {
	
	public static ArrayList<Integer>[]graph;
	
	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		
		graph=new ArrayList[N];
		
		for(int i=0;i<N;i++){
			graph[i]=new ArrayList<>();
		}
		
		for(int i=1;i<N;i++){
			int a=sc.nextInt();
			graph[a-1].add(i);
		}
		//??????
		System.out.println(dfs(0)-1);
		
	}
	private static int dfs(int v){
		if(graph[v].isEmpty())return 1;
		
		int[] temp=new int[graph[v].size()];
		for(int i=0;i<temp.length;i++){
			int u=graph[v].get(i);
			temp[i]=dfs(u);
		}
		Arrays.sort(temp);
		int max=0;
		for(int t:temp){
			if(t<=max){
				t++;
			}
			else{
				max=t;
			}
			max++;
		}
		return max;
	}
} Note: ./Main.java uses unchecked or unsafe operations.
Note: Recompile with -Xlint:unchecked for details.