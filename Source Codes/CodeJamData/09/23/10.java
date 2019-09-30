import java.io.*;
import java.util.*;

public class Main{

	Scanner in;
	PrintWriter out;

	int[] dx = new int[]{-1,1,0,0};
	int[] dy = new int[]{0,0,-1,1};

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = in.nextInt();
		int MIN = -1000;
		int MAX = 1000;
		boolean[][][] was = new boolean[20][20][MAX-MIN+1];
		int[][][] px = new int[20][20][MAX-MIN+1];
		int[][][] py = new int[20][20][MAX-MIN+1];
		int[][][] pz = new int[20][20][MAX-MIN+1];
		char[][][] pr = new char[20][20][MAX-MIN+1];
		int[] qx = new int[20*20*(MAX-MIN+1)+1];
		int[] qy = new int[20*20*(MAX-MIN+1)+1];
		int[] qz = new int[20*20*(MAX-MIN+1)+1];
		String[] s = new String[20];
		String[] res = new String[100];
		int[] v = new int[100];
		boolean[] br = new boolean[20*20*(MAX-MIN+1)+1];
		for(int __=0;__<_;__++){
			out.println("Case #"+(__+1)+":");
			int w = in.nextInt();
			int q = in.nextInt();
			for(int i=0;i<w;i++){
				s[i] = in.next();
			}
			for(int i = 0;i<w;i++)
				for(int j = 0;j<w;j++)
					Arrays.fill(was[i][j],false);
			for(int i=0;i<q;i++){
				v[i] = in.nextInt();res[i]="";
			}
			int ost = q;
			int f = 0;
			int l = 0;
			Arrays.fill(br,false);
			for(int c = 0;c<10;c++){
				for(int i = 0;i<w;i++)
					for(int j = 0;j<w;j++){
						if (s[i].charAt(j)=='0'+c){
							was[i][j][c-MIN]=true;
							pr[i][j][c-MIN]=0;
							qx[l] = i;
							qy[l] = j;
							qz[l] = c-MIN;
							for (int k = 0;k<q;k++)
								if (v[k]==c && res[k]==""){
									res[k] = ""+c;
									ost--;
								}
							l++;
						}
					}
				if (l>0) br[l-1] = true;
			}
			char[] ss = new char[]{'+','-'};
			int t = -1;
			while (f<l){
				for(int uu=0;uu<2;uu++){
				char sign = ss[uu];
				for(int ee=0;ee<10;ee++){
				t = f-1;
				while (t<f || !br[t]){
					t++;
					int xx = qx[t]; 
					int yy = qy[t];
					int zz = qz[t];
					for(int i = 0;i<4;i++)
						if (xx+dx[i]>=0 && xx+dx[i]<w && yy+dy[i]>=0 && yy+dy[i]<w){
							int tx = xx+dx[i];
							int ty = yy+dy[i];
							if (s[tx].charAt(ty)==sign){
								for(int j = 0;j<4;j++){
									if (tx+dx[j]>=0 && tx+dx[j]<w && ty+dy[j]>=0 && ty+dy[j]<w && s[tx+dx[j]].charAt(ty+dy[j])=='0'+ee){	
										int sx = tx+dx[j];
										int sy = ty+dy[j];
										int sz = zz+s[sx].charAt(sy)-'0';
										if (sign=='-') sz = zz-(s[sx].charAt(sy)-'0');
										if (sz>=0 && sz<=MAX-MIN){
											if (!was[sx][sy][sz]){
												was[sx][sy][sz] = true;
												px[sx][sy][sz] = xx;
												py[sx][sy][sz] = yy;
												pz[sx][sy][sz] = zz;
												pr[sx][sy][sz] = sign;
												for(int o = 0;o<q;o++)
													if (v[o]==sz+MIN && res[o]==""){
														res[o] = ""+s[sx].charAt(sy);
														int cx = sx;
														int cy = sy;
														int cz = sz;
														while (pr[cx][cy][cz]!=0){
															res[o] = pr[cx][cy][cz]+res[o];
															int hx = px[cx][cy][cz];
															int hy = py[cx][cy][cz];
															int hz = pz[cx][cy][cz];
															cx = hx; cy = hy; cz = hz;
															res[o] = s[cx].charAt(cy)+res[o];
														}
														ost--;
													}
												qx[l]=sx;
												qy[l]=sy;
												qz[l]=sz;
												l++;

											}
										}
									}
								}
							}
						}
				}
				br[l-1] = true;
				}
				}
				if (ost==0) break;
				f = t+1;
			}
			for(int i = 0;i<q;i++)
				out.println(res[i]);


		}
		
	}

	public void close() throws Exception{
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
					System.out.println(E);
					throw new RuntimeException(E);
				}
			}
		}.start();
	}
}
