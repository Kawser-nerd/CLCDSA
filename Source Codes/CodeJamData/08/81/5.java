import java.io.*;
import java.util.*;

public class Main{
	
	Scanner in;
	PrintWriter out;
	
	double rx = 1e100;
	double ry = 1e100;
	double eps = 1e-8;
	
	int[][] per = new int[][]{{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
	
	public void tr(int p1, int p2, int[] _x1, int[] _y1, int[] _x2, int[] _y2){
		int[] x1 = new int[3];
		int[] y1 = new int[3];
		int[] x2 = new int[3];
		int[] y2 = new int[3];
		for(int i = 0;i<3;i++){
			x1[i] = _x1[per[p1][i]];
			y1[i] = _y1[per[p1][i]];
			x2[i] = _x2[per[p2][i]];
			y2[i] = _y2[per[p2][i]];
		}
		int dx1 = x1[1]-x1[0];
		int dy1 = y1[1]-y1[0];
		int dx2 = x2[1]-x2[0];
		int dy2 = y2[1]-y2[0];
		double d = -dx1*dx1-dy1*dy1;
		double a = (-dx2*dx1-dy2*dy1)/d;
		double b = (dx1*dy2-dy1*dx2)/d;
		//System.out.println((a*dx1+b*dy1)-dx2);
		//System.out.println((-b*dx1+a*dy1)-dy2);
		double u = a*x1[0]+b*y1[0]-x2[0];
		double v = -b*x1[0]+a*y1[0]-y2[0];
		//System.out.println(u+" "+v+" "+a+" "+b+" "+d+" "+dx1+" "+dy1+" "+dx2+" "+dy2);
		for(int i = 0;i<3;i++){
			if (Math.abs(a*x1[i]+b*y1[i]-u-x2[i])>eps) return;
			if (Math.abs(-b*x1[i]+a*y1[i]-v-y2[i])>eps) return;
		}
		//System.out.println("!!!");
		double dd = (a-1)*(a-1)+b*b;
		rx= (u*(a-1)-v*b)/dd;
		ry= ((a-1)*(v)+b*u)/dd;
		//System.out.println(rx+" "+ry);
	}
	
	public void solve(int __) throws Exception{
		out.print("Case #"+__+": ");
		int[] x1 = new int[3];
		int[] y1 = new int[3];
		int[] x2 = new int[3];
		int[] y2 = new int[3];
		for(int i = 0;i<3;i++){
			x1[i] = in.nextInt();
			y1[i] = in.nextInt();
		}
		for(int i = 0;i<3;i++){
			x2[i] = in.nextInt();
			y2[i] = in.nextInt();
		}
		for(int i = 0;i<6;i++)
			for(int j = 0;j<6;j++)
				tr(i,j,x1,y1,x2,y2);
		if (rx==1e100 || ry==1e100) out.println("No Solution");
		else out.println(rx+" "+ry);
	}
	public void run() throws Exception{		
		in = new Scanner(new File("input.txt"));
		out = new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = in.nextInt();
		for(int __=0;__<_;__++){
			solve(__+1);
		}
		out.close();
	}
	
	public static void main(String[] args){
		new Thread(){
			public void run(){
				try{
					new Main().run();
				} catch (Exception E){
					throw new RuntimeException(E);
				}
			}
		}.start();
	}
}