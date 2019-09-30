import java.io.*;
import java.util.*;

public class Main{
	
	Scanner in;
	PrintWriter out;
	
	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out = new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			int n = in.nextInt();
			int[] x = new int[n];
			int[] y = new int[n];
			int A = in.nextInt();
			int B = in.nextInt();
			int C = in.nextInt();
			int D = in.nextInt();
			long x0 = in.nextInt();
			long y0 = in.nextInt();
			int M = in.nextInt();
			x[0] = (int)x0; y[0] = (int)y0;
			for(int i = 1; i<n;i++){
				x0 = (A*x0+B)%M;
				y0 = (C*y0+D)%M;
				x[i] = (int)x0; y[i] = (int)y0;
				//System.out.println(x0+" "+y0);
			}
			long[][] a = new long[3][3];
			for(int i = 0;i<n;i++){
				a[x[i]%3][y[i]%3]++;
			}
			long res = 0;
			for(int i1 = 0; i1<3;i1++)
				for(int j1 = 0; j1<3;j1++)
					for(int i2 = 0; i2<3;i2++)
						for(int j2 = 0; j2<3;j2++)
							if (i1<i2 || (i1==i2 && j1<=j2))
								for(int i3 = 0; i3<3;i3++)
									for(int j3 = 0; j3<3;j3++)
										if (i2<i3 || (i2==i3 && j2<=j3))
											if ((i1+i2+i3)%3==0 && (j1+j2+j3)%3==0){
												long u = a[i1][j1];
												long v = a[i2][j2];
												long w = a[i3][j3];
												int d = 0;
												if (i1==i2 && j1==j2) {v--; d++;}
												if (i1==i3 && j1==j3) {w--; d++;}
												if (i2==i3 && j2==j3) {w--; d++;}
												long r =u*w*v;
												if (d==1) r/=2;
												if (d>=2) r/=6;
												res+=r;
											}
			out.println("Case #"+(__+1)+": "+res);
				
		}
		out.close();
	}

	public static void main(String[] args) throws Exception{
		new Main().run();
	}	
}