import java.io.*;
import java.util.*;

public class Main{


	Scanner in;
	PrintWriter out;

	char[] cur;
	char[][] z;
	int num;
	int MOD = 10007;

	public void genall(int n,  char c){
		if (n>0){
			for(char cc=c;cc<='z';cc++){
				cur[cur.length-n] = cc;
				genall(n-1,cc);
			}
		} else {
			for(int i = 0;i<cur.length;i++)
				z[num][i] = cur[i];
			num++;	
		}

			
	}

	public boolean loe(char[] a, char[] b){
		for(int i = 0;i<a.length;i++){
			if (a[i]<b[i]) return true;
			if (a[i]>b[i]) return false;
		}
		return true;
			
	}

	public int search(char[] u){
		int l = 0;
		int r = num;
		while (r-l>1){
			int x = (r+l)>>1;
			if (loe(z[x],u))
				l = x;
			else
				r = x;
		}
		return l;
	}

	public void sol() throws Exception{
		int m = in.nextInt();
		int n = in.nextInt();
		num = 0;
		cur = new char[n];
		z = new char[100000][n];
		genall(n,'a');
		String[] s = new String[m];
		for(int i = 0;i<m;i++)
			s[i] = in.next();
		int[] ol = new int[num];
		int[] ne = new int[num];
		ol[0] = 1;
		char[] u = new char[n];
		for(int i = 0;i<m;i++)
			for(int j = n-1;j>=0;j--){
				for(int e = 0;e<num;e++){
					if (s[i].charAt(j)!='.' && s[i].charAt(j)!=z[e][j]){
						ne[e] = 0;
						continue;
					}
					char maxc = z[e][j];
					char minc = 'a';
					if (j>0) minc = z[e][j-1];
					for(int k = 0;k<n;k++)
						u[k] = z[e][k];
					ne[e] = 0;
					for(char cc = minc;cc<=maxc;cc++){
						u[j] = cc;
						int t = search(u);
						/*System.out.println(t);
						for(int ii = 0;ii<n;ii++)
							System.out.print(u[ii]);
						System.out.println();
						for(int ii = 0;ii<n;ii++)
							System.out.print(z[t][ii]);
						System.out.println();*/
						ne[e]+=ol[t];
						if (ne[e]>=MOD)
							ne[e]-=MOD;
					}
				}
				int [] te = ne;
				ne = ol;
				ol = te;
			}
		int sum = 0;
		for(int i = 0;i<num;i++){
			sum+=ol[i];
			if (sum>=MOD)
				sum-=MOD;
		}
		out.println(sum);
	}

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			out.print("Case #"+(__+1)+": ");
			sol();
		}
	}

	public void close(){
		out.close();
	}


	public static void main(String[] args){
		new Thread(){
			public void run(){
				try{
					Main a = new Main();
					a.run();
					a.close();
				} catch (Exception E){
					throw new RuntimeException(E);
				}
			}
		}.start();
	}
}
