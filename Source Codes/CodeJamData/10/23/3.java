import java.io.*;
import java.util.*;

public class Main{
	Scanner in;
	PrintWriter out;

	long[][] a;
	long[] s;
	int mod = 100003;


	public void prepare(){
		long[][] c = new long[501][501];
		for(int i = 0;i<=500;i++){
			c[i][0] = 1;
			for(int j = 1;j<=i;j++){
				c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
			}
		}
			
		a = new long[501][501];
		s = new long[501];
		a[1][1] = 1;
		for(int i=2;i<=500;i++){
			a[i][1] = 1;
			s[i] = 1;
			for(int j = 2;j<i;j++){
				for(int z = 1;z<j;z++){
					a[i][j] = (a[i][j] + a[j][z]*c[i-j-1][j-z-1])%mod;
				}
				s[i] = (s[i] + a[i][j])%mod;
			}
		}
	}

	

	public void solve(){
		int n = in.nextInt();
		out.println(s[n]);

	}

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter("output.txt"));
		prepare();
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			out.print("Case #"+(__+1)+": ");
			solve();
		}
	}

	public void close() throws Exception{
		out.close();
	}

	public static void main(String[]  args){
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
