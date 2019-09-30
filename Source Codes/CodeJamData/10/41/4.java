import java.io.*;
import java.util.*;

public class Main{
	Scanner in;
	PrintWriter out;

	public void solve(){
		int n = in.nextInt();
		int[][] a = new int[2*n+1][2*n+1];

		for(int i = 0;i<=2*n;i++){
			for(int j = 0;j<=2*n;j++){
				int d = Math.abs(i-n)+Math.abs(j-n);
				if (d<=n-1 && (((n-1-d)&1)==0)) {
					a[i][j] = in.nextInt();
//					System.out.println(i+" "+j+" "+a[i][j]);
				}
				else a[i][j] = -1;
			}
		}
		int best = 2*n;
		for(int i = 0;i<=2*n;i++)
			for(int j =0;j<=2*n;j++){
				boolean ok = true;
				for(int l = 0;l<=2*n && ok;l++)
					for(int r = 0;r<=2*n && ok;r++) if (a[l][r]!=-1){
						int l1 = 2*i-l;
						if (l1 >= 0 && l1<=2*n && a[l1][r]!=a[l][r] && a[l1][r]!=-1) {
//							System.out.println(i+" "+j+" "+l+" "+r);
							ok = false; break;
						}
						int r1 = 2*j-r;
						if (r1 >= 0 && r1<=2*n && a[l][r1]!=a[l][r] && a[l][r1]!=-1) {
//							System.out.println(i+" "+j+" "+l+" "+r);
							ok = false; break;
						}
					}
				if (ok && Math.abs(i-n)+Math.abs(j-n)<best){
					best = Math.abs(i-n)+Math.abs(j-n);
//					System.out.println((i-n)+" "+(j-n));
				}
			}
//		System.out.println(best);
		int size1 = n*n;
		int size2 = (n+best)*(n+best);
		out.println(size2-size1);
	}

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter("output.txt"));
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
