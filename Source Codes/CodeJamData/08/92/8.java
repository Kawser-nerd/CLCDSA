import java.io.*;
import java.util.*;

public class Main{
	
	Scanner in;
	PrintWriter out;
	
	public void solve() throws Exception{
		int w = in.nextInt();
		int h = in.nextInt();
		int[] dx = new int[2];
		int[] dy = new int[2];
		dx[0] = in.nextInt();
		dy[0] = in.nextInt();
		dx[1] = in.nextInt();
		dy[1] = in.nextInt();
		int a = in.nextInt();
		int b = in.nextInt();
		boolean[][] g = new boolean[w][h];
		int[] xx = new int[w*h];
		int[] yy = new int[w*h];
		int f = 0; int l = 1;
		xx[0] = a; yy[0] = b;
		g[a][b] = true;
		int v = 0;
		while (f<l){
			int x = xx[f]; int y = yy[f];
			v++;
			for(int i = 0;i<2;i++){
				if (x+dx[i]>=0 && x+dx[i]<w &&
					y+dy[i]>=0 && y+dy[i]<h && !g[x+dx[i]][y+dy[i]]){
					g[x+dx[i]][y+dy[i]] = true;
					xx[l] = x+dx[i];
					yy[l] = y+dy[i];
					l++;
				}
			}
			f++;
		}
		out.println(v);
		
	}
	
	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = in.nextInt();
		for(int __ = 0;__<_;__++){
			out.print("Case #"+(__+1)+": ");
 			solve();
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