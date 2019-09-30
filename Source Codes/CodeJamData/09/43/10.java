import java.io.*;
import java.util.*;

public class Main{
	Scanner in;
	PrintWriter out;

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter("output.txt"));
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			out.print("Case #"+(__+1)+": ");
			int n = in.nextInt();
			int k = in.nextInt();
			int[][] a = new int[n][k];
			for(int i = 0;i<n;i++)
				for(int j = 0;j<k;j++)
					a[i][j] = in.nextInt();
			int res = 0;
			for(int nn=1;nn<(1<<n);nn++){
				boolean ok = true;
				for(int i = 0;i<n && ok;i++) if ((nn & (1<<i))!=0)
					for(int j = 0; j<n && ok;j++) if ((nn & (1<<j))!=0){
						boolean o = false;
						for(int l=0;l<(k-1);l++)
							if (!((a[i][l]<a[j][l] && a[i][l+1]<a[j][l+1]) || (a[i][l]>a[j][l] && a[i][l+1]>a[j][l+1]))){
								o = true; break;
							}
						if (!o) ok = false;
					}
				if (ok){
					int cc = 0;
					for(int i = 0;i<n;i++) if ((nn & (1<<i))!=0) cc++;
					if (res<cc) res = cc;
				}
			}
			out.println(res);
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
