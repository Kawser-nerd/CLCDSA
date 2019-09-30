
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class C {
	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;
	final static double INF = 1e30;
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
		final int NUM_CASES = readInt();
		for(int casenum = 1; casenum <= NUM_CASES; casenum++)	{
			pw.print("Case #" + casenum + ": ");
			int n = readInt();
			String[] start = new String[n];
			int[] speed = new int[n];
			int[] loc = new int[n];
			for(int i = 0; i < n; i++){
				start[i] = nextToken();
				speed[i] = readInt();
				loc[i] = readInt();
			}
			TreeSet<Fraction> set = new TreeSet<Fraction>();
			for(int i = 0; i < n; i++)	{
				for(int j = 0; j < n; j++)	{
					if(speed[i] > speed[j] && loc[j] > loc[i] + 5)	{
						int num = loc[j] - loc[i] - 5;
						int dem = speed[i] - speed[j];
						set.add(new Fraction(num, dem));
					}
				}
			}
			double[] time = new double[set.size() + 1];
			int c = 1;
			for(Fraction out: set)
				time[c++] = out.eval();
			time[0] = 0;
			LinkedList<Integer> now = new LinkedList<Integer>();
			int startMask = 0;
			for(int i = 0; i < n; i++)
				if(start[i].equals("R"))
					startMask |= 1 << i;
			now.add(startMask);
			int qqq = 0;
			for(qqq = 0; qqq < time.length; qqq++)	{
				if(now.isEmpty())
					break;
				Set<Integer> seen = new HashSet<Integer>();
				LinkedList<Integer> next = new LinkedList<Integer>();
				outer: while(!now.isEmpty())	{
					int curr = now.removeFirst();
					double[] currT = new double[n];
					for(int i = 0; i < n; i++)	{
						currT[i] = speed[i] * time[qqq] + loc[i];
					}
					for(int i = 0; i < n; i++)	{
						for(int j = 0; j < n; j++)	{
							if(i != j && on(curr, i) == on(curr,j))	{
								double dist = currT[i] - currT[j];
								if(dist >= -5+1e-8 && dist <= 5-1e-8)
									continue outer;
							}
						}
					}
					for(int i = 0; i < n; i++)	{
						currT[i] = speed[i] * (time[qqq]+1e-4) + loc[i];
					}
					boolean canProceed = true;
					for(int i = 0; i < n; i++)	{
						for(int j = 0; j < n; j++)	{
							if(i != j && on(curr, i) == on(curr,j))	{
								double dist = Math.abs(currT[i] - currT[j]);
								if(dist <= 5-1e-8)
									canProceed = false;
							}
						}
					}
					if(canProceed)	{
						next.add(curr);
					}
					for(int i = 0; i < n; i++)	{
						int nextMask = curr ^ (1<<i);
						if(seen.add(nextMask))
							now.addLast(nextMask);
					}
				}
				now = next;
			}
			if(!now.isEmpty())	{
				pw.println("Possible");
			}
			else	{
				pw.println(time[--qqq]);
			}
		}
		pw.close();
	}

	public static String printString(int mask, int len)	{
		String s = Integer.toBinaryString(mask);
		while(s.length() < len)
			s = '0' + s;
		return new StringBuilder(s).reverse().toString();
	}
	
	public static boolean on(int a, int b)	{
		return ((a & (1 << b)) != 0);
	}
	
	static class Fraction implements Comparable<Fraction> {
		public BigInteger n,d;
		public Fraction(int in)	{
			this(BigInteger.valueOf(in), BigInteger.ONE);
		}
		public Fraction(int inA, int inB)	{
			this(BigInteger.valueOf(inA), BigInteger.valueOf(inB));
		}
		public double eval()	{
			return n.doubleValue() / d.doubleValue();
		}
		public Fraction(BigInteger a, BigInteger b)	{
			BigInteger g = gcd(a.abs(), b.abs());
			n = a.divide(g);
			d = b.divide(g);
		}
		public Fraction add(Fraction in)	{
			return new Fraction(n.multiply(in.d).add(d.multiply(in.n)), d.multiply(in.d));
		}
		public Fraction subtract(Fraction in)	{
			return new Fraction(n.multiply(in.d).subtract(d.multiply(in.n)), d.multiply(in.d));
		}
		public Fraction multiply(Fraction in)	{
			return new Fraction(n.multiply(in.n), d.multiply(in.d));
		}
		public Fraction divide(Fraction in)	{
			return new Fraction(n.multiply(in.d), d.multiply(in.n));
		}
		public static BigInteger gcd(BigInteger a, BigInteger b)	{
			if(b.equals(BigInteger.ZERO))
				return a;
			if(a.equals(BigInteger.ZERO))
				return b;
			return gcd(b, a.mod(b));
		}
		public int compareTo(Fraction f)	{
			double test = n.doubleValue() / d.doubleValue();
			double other = f.n.doubleValue() / f.d.doubleValue();
			if(test < other)
				return -1;
			if(test > other)
				return 1;
			return 0;
		}
	}
	
	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			if (!br.ready()) {
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}
