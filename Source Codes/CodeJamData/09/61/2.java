
import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class A implements Runnable {
	
	int[][] a = new int [128][128];
	int[] m = new int[128];
	int days,n;
	
	static class Fr
	{
		public BigInteger a;
		public BigInteger b;
		public Fr(BigInteger aa, BigInteger bb)
		{
			BigInteger dd = aa.gcd(bb);
			a = aa.divide(dd);
			b = bb.divide(dd);
		}
		public Fr add(Fr x)
		{
			return new Fr(a.multiply(x.b).add(b.multiply(x.a)),b.multiply(x.b));
		}
	}
    
	BigInteger solve(int[] st)
	{
		BigInteger[][] d = new BigInteger[n+1][n+1];
		for (int i = 0; i<=n; i++)
			d[0][i]=BigInteger.ZERO;
		d[0][0] = BigInteger.ONE;
		for (int i = 0; i<n; i++)
			for (int j = 0; j <= n; j++)
			{
				d[i+1][j]=d[i][j].multiply(BigInteger.valueOf(days-st[i]));
				if (j>0)
					d[i+1][j] = d[i+1][j].add(d[i][j-1].multiply(BigInteger.valueOf(st[i])));
			}
		BigInteger res = BigInteger.ZERO;
		for (int i = 1; i <= n; i++)
			res = res.add(d[n][i].multiply(BigInteger.valueOf(i*i)));
		return res;
	}
	
      void solve() throws Exception {
            Locale.setDefault(Locale.US); // necessary for floats I/O
           
          Scanner in = new Scanner(new File("A-large.in"));
          PrintWriter out = new PrintWriter("A-large.out");
          
          int tests = in.nextInt();
          for (int test=0; test<tests; test++)  
          {
        	  System.err.println(test+1);
        	  System.err.flush();
        	  days = in.nextInt();
        	  n = in.nextInt();
        	  java.util.List<Integer> qq = new ArrayList<Integer>();
        	  qq.add(0);
        	  for (int i = 0; i < n; i++)
        	  {
        		  m[i] = in.nextInt();
        		  int pos = 0;
        		  a[i][0]=0;
        		  for (int j = 1; j < m[i]; j++)
        		  {
        			  qq.add(a[i][j]=in.nextInt()-1);
        		  }
        	  }
        	  qq.add(days);
        	  Integer[] qw = qq.toArray(new Integer[0]);
        	  Arrays.sort(qw);
        	  BigInteger res = BigInteger.ZERO;
              for (int id = 0; id < qw.length-1; id++)
            	  if (qw[id] < qw[id+1] && qw[id] < days)
            	  {
            		  int day=qw[id];
            		  int ln = qw[id+1]-qw[id];
	            	  int[] st = new int[n];
	            	  for (int i = 0; i < n; i++)
	            	  {
	            		  st[i]=0;
	            		  for (int j = 0; j<m[i] && a[i][j]<=day; j++)
	            			  st[i]++;
	            	  }
	            	  res = res.add(solve(st).multiply(BigInteger.valueOf(ln)));
	              }
              BigInteger denom = BigInteger.ONE;
              for (int i =0; i < n; i++)
            	  denom=denom.multiply(BigInteger.valueOf(days));
              BigInteger dd = res.gcd(denom);
              res = res.divide(dd);
              denom = denom.divide(dd);
              out.print("Case #");
              out.print(test+1);
              out.print(": ");
              out.print(res.divide(denom));
              out.print("+");
              out.print(res.mod(denom));
              out.print("/");
              out.println(denom);
          }
          out.flush(); //  !!!        
      }
     
      @Override
      public void run() {
            try {
                  solve();
            }
            catch (Exception e) {
                  e.printStackTrace();
                  throw new IllegalStateException();
            }
     
      }
      public static void main(String[] args) {
            new Thread(new A()).run();
      }
}