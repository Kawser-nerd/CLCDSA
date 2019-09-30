import java.io.*;
import java.util.*;

public class Main{
	Scanner in;
	PrintWriter out;

	int n;
	int m;
	boolean[][] c;
	public long encode(boolean[][] a){
		long res = 0;
		int xx = -1;
		for(int i=0;i<n;i++){
			xx = -1;
			for(int j=0;j<m;j++)
				if (a[i][j]){
					xx = i; break;
				}
			if (xx!=-1) {
				break;
			}
		}
		for(int i=xx;i<n && i<xx+6;i++){
			int x = -1;
			for(int j=0;j<m;j++)
				if (a[i][j]){
					x = j; break;
				}
			if (x == -1){
				res = (res<<4)+15; continue;
			}
			for(int k=0;k<6;k++) if (x+k<m){
				res = res << 1; 
				if (a[i][x+k]) res++;
			}
			res = (res<<4) + x;

		}
		res = (res<<4)+xx;
		return res;
	}

	public void decode(long r, boolean[][] a){
		for(int i = 0;i<n;i++)
			Arrays.fill(a[i],false);
		int xx = (int)(r & 15);
		//System.out.println(xx);
		r = r>>4;
		for(int i = Math.min(xx+5,n-1);i>=xx;i--){
			int x = (int)(r & 15);
			//System.out.println(x);
			r = r>>4;
			if (x==15) continue;
			for(int j = Math.min(x+5,m-1);j>=x;j--){
				if ((r & 1)==1) a[i][j] = true;
				r = r >> 1;
			}
		}
	}


	int[] dx = new int[]{1,-1,0,0};
	int[] dy = new int[]{0,0,1,-1};
	public boolean canmove(boolean[][] a, int i, int j, int k){
		return ((i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<m && !a[i+dx[k]][j+dy[k]] && !c[i+dx[k]][j+dy[k]]) && 
		   (i-dx[k]>=0 && i-dx[k]<n && j-dy[k]>=0 && j-dy[k]<m && !a[i-dx[k]][j-dy[k]] && !c[i-dx[k]][j-dy[k]]));
	}

	boolean[][] g = new boolean[12][12];

	public int poisk(boolean[][]a, int i, int j){
		g[i][j] = true;
		int r = 1;
		for(int k = 0;k<4;k++){
			if(i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<m && a[i+dx[k]][j+dy[k]] && !g[i+dx[k]][j+dy[k]])
				r+=poisk(a,i+dx[k],j+dy[k]);
		}
		return r;
	}

	int re;

	public boolean connected(boolean[][] a){
		int x = -1; int y = -1;
		for(int i = 0;i<n && x==-1;i++)
			for(int j = 0;j<m;j++){
				if (a[i][j]){
					x = i;
					y = j;
					break;
				}
			}
		for(int i = 0;i<n;i++)
			Arrays.fill(g[i],false);
		return (poisk(a,x,y)==re);
	}

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter("output.txt"));
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			n = in.nextInt();
			m = in.nextInt();
			out.print("Case #"+(__+1)+": ");
			String[] s = new String[n];
			boolean[][] a = new boolean[n][m];
			boolean[][] b = new boolean[n][m];
			c = new boolean[n][m];
			re = 0;
			for(int i = 0;i<n;i++){
				s[i] = in.next();
				for(int j = 0;j<m;j++){
					if (s[i].charAt(j)=='x' || s[i].charAt(j)=='w') b[i][j] = true;
					if (s[i].charAt(j)=='o' || s[i].charAt(j)=='w') { a[i][j] = true; re++;}
					if (s[i].charAt(j)=='#') c[i][j] = true;
				}
			}
			HashSet<Long> w = new HashSet<Long>();
			int MAX = 10000000;
			long[] q = new long[MAX];
			int[] r = new int[MAX];
			q[0] = encode(a);
			w.add(q[0]);
			long pp = encode(b);
			if (q[0]==pp){
				out.println(0); continue;
			}
			int f = 0; int l = 1;
			boolean ok = false;
			while (f<l){
				long cur = q[f++];
				decode(cur,a);
				int aa=r[f-1];
				//System.out.println(q[f-1]);
				/*for(int i = 0;i<n;i++){
					for(int j = 0;j<m;j++)
						System.out.print(a[i][j]);
					System.out.println();
				}*/
				boolean o = connected(a);
				for(int i = 0;i<n && !ok;i++)
					for(int j = 0;j<m && !ok;j++){
						if (a[i][j])
							for(int k = 0;k<4 && !ok;k++)
								if (canmove(a,i,j,k)){
									a[i][j] = false;
									a[i+dx[k]][j+dy[k]]=true;
									if ((o || connected(a))){
										long p = encode(a);
										if (p == pp){
											out.println(aa+1); ok = true; break;
										}
										if (!w.contains(p)){
											//System.out.println("+");
											/*for(int ii = 0;ii<n;ii++){
												for(int jj = 0;jj<m;jj++)
													System.out.print(a[ii][jj]);
												System.out.println();
											}*/
											r[l] = aa+1;
											q[l++] = p;
											w.add(p);
										}
									}
									a[i][j] = true;
									a[i+dx[k]][j+dy[k]]=false;
								}
					}
			}
			if (!ok) out.println("-1");

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
