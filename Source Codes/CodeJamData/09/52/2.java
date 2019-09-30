import java.io.*;
import java.util.*;

public class Main{
	Scanner in;
	PrintWriter out;

	int M = 10009;

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter("output.txt"));
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			out.print("Case #"+(__+1)+":");
			String  p = in.next();
			int k = in.nextInt()+1;
			int n = in.nextInt();
			String[] s = new String[n];
			int[][] cou = new int[n][26];
			for(int i = 0;i<n;i++){
				s[i] = in.next();
				for(int j = 0;j<s[i].length();j++)
					cou[i][s[i].charAt(j)-'a']++;
			}
			String[] pp = p.split("\\+");
			int[] re = new int[k+1];
			for(int o = 0;o<pp.length;o++){
				String r = pp[o];
				int[][] res = new int[k+1][1<<r.length()];
				res[0][0] = 1;
				for(int i = 0;i<k;i++){
					for(int j = 0;j<(1<<r.length());j++)
						for(int l = 0;l<n;l++){
							for(int jj = 0;jj<(1<<r.length());jj++) 
								if ((j & jj) == jj){
									int t = res[i][jj];
									for(int kk = 0;kk<r.length();kk++){
										if ((j & (1<<kk))!=(jj & (1<<kk))){
											t = (t*cou[l][r.charAt(kk)-'a'])%M;
										}
									}
									res[i+1][j] = (res[i+1][j]+t)%M;
								}
						}
					re[i+1] = (re[i+1]+res[i][(1<<r.length())-1])%M;
				}
					
			}
			for(int i = 2;i<=k;i++)
				out.print(" "+re[i]);
			out.println();
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
