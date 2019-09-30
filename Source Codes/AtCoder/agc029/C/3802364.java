import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;
import static java.lang.Math.*;
 
/* spar5h */
 
public class Main implements Runnable {    
	
	public void run() {
		
		InputReader s = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = s.nextInt();
		
		int[] a = new int[n];
		
		for(int i = 0; i < n; i++)
			a[i] = s.nextInt();
		
		TreeMap<Integer, Integer> tm = new TreeMap<Integer, Integer>();
		
		int left = 1, right = n;
		
		int res = n;
		
		while(left <= right) {
			
			int k = (left + right) / 2;
			
			boolean check = true;
			
			tm.clear();
			
			int i = 1;
			
			while(i < n && a[i] > a[i - 1])
				i++;
			
			tm.put(a[i - 1] - 1, 0);
			
			while(i < n) {
		
				tm.put(a[i] - 1, tm.ceilingEntry(a[i] - 1).getValue());
				
				while(tm.lastKey() > a[i] - 1)
					tm.remove(tm.lastKey());
				
				int j = a[i] - 1;
				
				while(tm.floorEntry(j) != null) {
					
					int temp = tm.ceilingEntry(j).getValue();
					
					if(tm.ceilingEntry(j).getValue() < k - 1) {
						tm.put(j, tm.ceilingEntry(j).getValue() + 1); 
						
						if(j - 1 >= 0 && tm.get(j - 1) == null)
							tm.put(j - 1, temp);
						
						break;
					}
					
					tm.put(tm.ceilingKey(a[i] - 1), 0);
					
					j--;
				}
				
				if(tm.floorEntry(j) == null) {
					check = false; break;
				}
				
				int temp = a[i] - 1;
				
				i++;
				
				while(i < n && a[i] > a[i - 1]) 
					 i++;
				
				if(a[i - 1] - 1 > temp)
					tm.put(a[i - 1] - 1, 0);
			}
			
			if(check) {
				res = k; right = k - 1;
			}
			else 
				left = k + 1;
		}
		
		w.println(res);
		
		w.close();
	}
 
	static class InputReader {
		
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;
		
		public InputReader(InputStream stream) {
			this.stream = stream;
		}
		
		public int read() {
			
			if (numChars==-1) 
				throw new InputMismatchException();
			
			if (curChar >= numChars) {
				
				curChar = 0;
				
				try {
					numChars = stream.read(buf);
				}
				catch (IOException e) {
					throw new InputMismatchException();
				}
				
				if(numChars <= 0)				
					return -1;
			}
			
			return buf[curChar++];
		}
		 
		public String nextLine() {
			
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			String str = "";
	        
			try {
	            str = br.readLine();
	        }
	        catch (IOException e) {
	            e.printStackTrace();
	        }
			
	        return str;
		}
		
		public int nextInt() {
		
			int c = read();
			
			while(isSpaceChar(c)) 
				c = read();
			
			int sgn = 1;
			
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			
			int res = 0;
			
			do {
				if(c<'0'||c>'9') 
					throw new InputMismatchException();
				
				res *= 10;
				res += c - '0';
				c = read();
			}
			while (!isSpaceChar(c)); 
			
			return res * sgn;
		}
		
		public long nextLong() {
			
			int c = read();
			
			while (isSpaceChar(c))
				c = read();
			
			int sgn = 1;
			
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			
			long res = 0;
			
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				
				res *= 10;
				res += c - '0';
				c = read();
			}
			
			while (!isSpaceChar(c));
				return res * sgn;
		}
		
		public double nextDouble() {
			
			int c = read();
			
			while (isSpaceChar(c))
				c = read();
			
			int sgn = 1;
			
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			
			double res = 0;
			
			while (!isSpaceChar(c) && c != '.') {
				
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, nextInt());
				
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				
				res *= 10;
				res += c - '0';
				c = read();
			}
			
			if (c == '.') {
				
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) 
				{
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, nextInt());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			
			return res * sgn;
		}
		
		public String readString() {
			
			int c = read();
			
			while (isSpaceChar(c))
				c = read();
			
			StringBuilder res = new StringBuilder();
			
			do {
				res.appendCodePoint(c);
				c = read();
			} 
			while (!isSpaceChar(c));
			
			return res.toString();
		}
	 
		public boolean isSpaceChar(int c) {
			
			if (filter != null)
				return filter.isSpaceChar(c);
			
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
	 
		public String next() {
			return readString();
		}
		
		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	
	}
 
	public static void main(String args[]) throws Exception {
		new Thread(null, new Main(),"Main",1<<26).start();
	}
}