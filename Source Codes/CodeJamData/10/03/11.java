import java.io.*;
import java.util.*;

public class park {
	public static void main (String[] args) throws IOException{
		BufferedReader in=new BufferedReader(new FileReader("park.in"));
		PrintWriter out=new PrintWriter(new FileWriter("park.out"));
		int test=Integer.parseInt(in.readLine());
		for (int i=1; i<=test; i++){
			out.print("Case #"+i+": ");
			StringTokenizer st=new StringTokenizer(in.readLine());
			int runs=Integer.parseInt(st.nextToken());
			int cap=Integer.parseInt(st.nextToken());
			int groups=Integer.parseInt(st.nextToken());
			st=new StringTokenizer(in.readLine());
			int[] size=new int[groups];
			boolean flag=true;
			long help=0;
			for (int j=0; j<groups; j++){
				size[j]=Integer.parseInt(st.nextToken());
				help+=size[j];
				if (help>(long)cap) flag=false;
			}
			if (flag){
				out.println(help*runs);
				continue;
			}
			int[][] info=new int[groups][2]; //info[i][0] is the number of ppl that can ride, info[i][1] is index of nxt group
			int index=0;
			int sum=0;
			for (int j=0; index<groups; j++){
				if (j>=groups) j%=groups;
				if (sum+size[j]>0 && sum+size[j]<=cap)
					sum+=size[j];
				else{
					info[index][0]=sum;
					info[index][1]=j;
					sum-=size[index];
					j--;
					index++;
				}
			}
			int[] visited=new int[groups];
			long[] totals=new long[groups];
			int sofar=0;
			int curr=0;
			long ans=0;
			while(sofar<runs){
				if (visited[curr]!=0){
					int cycle=sofar-visited[curr]+1;
					runs-=visited[curr]-1;
					int n=runs/cycle-1;
					ans+=(ans-totals[visited[curr]-1])*n;
					n=runs%cycle;
					ans+=totals[visited[curr]-1+n]-totals[visited[curr]-1];
					sofar=runs;
				}
				else{
					totals[sofar]=ans;
					ans+=info[curr][0];
					sofar++;
					visited[curr]=sofar;
					curr=info[curr][1];
				}
			}
			out.println(ans);
		}
		out.close();
		System.exit(0);
	}
}
