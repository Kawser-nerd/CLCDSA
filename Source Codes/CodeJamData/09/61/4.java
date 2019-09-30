import java.io.*;
import java.util.*;
import java.math.*;

public class Main{

	int n;
	int m;
	int[][] d;
	public BigInteger[] sol(int x){
		BigInteger[][] r = new BigInteger[m+1][m+1];
		for(int i =0;i<=m;i++)
			Arrays.fill(r[i],BigInteger.ZERO);
		r[0][0] = BigInteger.ONE;
		for(int i = 0;i<m;i++){
			int t = 0;
			for(int j = 0;j<d[i].length;j++)
				if (d[i][j]<=x+1)
					t++;
			BigInteger tt = new BigInteger(""+(n-t));
			for(int j=0;j<=m;j++)
				r[i+1][j] = r[i+1][j].add(r[i][j].multiply(tt));
			tt = new BigInteger(""+(t));
			for(int j=0;j<m;j++)
				r[i+1][j+1] = r[i+1][j+1].add(r[i][j].multiply(tt));
		}
		return r[m];
	}

	Scanner in;
	PrintWriter out;

	public String solve() throws Exception{
		n = in.nextInt();
		m = in.nextInt();
		d = new int[m][];
		for(int i = 0;i<m;i++){
			int leng = in.nextInt();
			d[i] = new int[leng];
			d[i][0] = 1;
			for(int j =1;j<leng;j++)
				d[i][j] = in.nextInt();
		}
		BigInteger p = BigInteger.ZERO;
		BigInteger[] num = new BigInteger[m+1];
		for(int i = 1;i<=m;i++)
			num[i] = new BigInteger(""+(i*i));
		for(int i = 0;i<=10000 && i<n;i++){
			BigInteger[] t = sol(i);
			for(int e = 1;e<=m;e++)
				p = p.add(t[e].multiply(num[e]));
		}
		int q = 10001;
		for(int i = Math.max(q,n-10001);i<n;i++){
			BigInteger[] t = sol(i);
			for(int e = 1;e<=m;e++)
				p = p.add(t[e].multiply(num[e]));
		}
		int r = Math.max(q,n-10001);
		if (q<r){
			BigInteger[] t = sol(10001);
			for(int e = 1;e<=m;e++)
				p = p.add(t[e].multiply(num[e]).multiply(new BigInteger(""+(r-q))));
		}
		BigInteger p2 = BigInteger.ONE;
		for(int e = 0;e<m;e++)
			p2 = p2.multiply(new BigInteger(""+n));
		BigInteger g = p.gcd(p2);
		p = p.divide(g);
		p2=p2.divide(g);
		return (p.divide(p2)+"+"+p.remainder(p2)+"/"+p2);
			
	

	}

	public void run() throws Exception{
		in = new Scanner(new File("input.txt"));
		out= new PrintWriter(new FileWriter(new File("output.txt")));
		int _ = in.nextInt();
		for(int __ = 0;__<_;__++){
			out.print("Case #"+(__+1)+": ");
			out.println(solve());
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
