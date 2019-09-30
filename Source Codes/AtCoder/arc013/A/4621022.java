import java.util.*;
import java.io.*;
import java.math.*;

public class Main {

	void solve (FastScanner in, PrintWriter out) {
		
		int[] a = in.nextIntArray(3), b = in.nextIntArray(3);
		int x = (a[0]/b[0])*(a[1]/b[1])*(a[2]/b[2]);
		int y = (a[0]/b[1])*(a[1]/b[0])*(a[2]/b[2]);
		
		String s = "012";
		int max = Integer.MIN_VALUE;
		while (true) {
			max = Math.max(
					max, 
					(a[0]/b[s.charAt(0)-'0'])*(a[1]/b[s.charAt(1)-'0'])*(a[2]/b[s.charAt(2)-'0']));
			s = nextPermutation(s);
			if (s.equals("Final")) break;
		}
		
		out.println(max);
		
	}
	
	static String nextPermutation (String s) {
		ArrayList<Character> list = new ArrayList<>();
		for (int i=0; i<s.length(); i++) list.add(s.charAt(i));
		
		int pivotPos = -1;
		char pivot = 0;
		
		for (int i=list.size()-2; i>=0; i--) {
			if (list.get(i) < list.get(i+1)) {
				pivotPos = i;
				pivot = list.get(i);
				break;
			}
		}
		
		if (pivotPos==-1 && pivot==0) return "Final";
		
		int L = pivotPos+1, R = list.size()-1;
		int minPos = -1;
		char min = Character.MAX_VALUE;
		for (int i=R; i>=L; i--) {
			if (pivot < list.get(i)) {
				if (list.get(i) < min) {
					min = list.get(i);
					minPos = i;
				}
			}
		}
		
		Collections.swap(list, pivotPos, minPos);
		Collections.sort(list.subList(L, R+1));
		
		StringBuilder sb = new StringBuilder();
		for (int i=0; i<list.size(); i++) sb.append(list.get(i));
		
		return sb.toString();
		
	}



	public static void print (Object... ar) {
		System.out.println(Arrays.deepToString(ar));
	}

	public static void main(String[] args) {
		Main main = new Main();
		FastScanner in = new FastScanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		main.solve(in, out);
		in.close();
		out.close();
	}

	static class FastScanner {

		private InputStream in;
		private byte[] buffer = new byte[1024];
		private  int length = 0, p = 0;

		public FastScanner (InputStream stream) {
			in = stream;
		}
		public boolean hasNextByte () {
			if (p < length) return true;
			else {
				p = 0;
				try {length = in.read(buffer);}
				catch (Exception e) {e.printStackTrace();}
				if (length <= 0) return false;
			}
			return true;
		}
		public int readByte () {
			if (hasNextByte() == true) return buffer[p++];
			return -1;
		}
		public boolean isPrintable (int n) {return 33<=n&&n<=126;}
		public void skip () {
			while (hasNextByte() && !isPrintable(buffer[p])) p++;
		}
		public boolean hasNext () {skip(); return hasNextByte();}
		public String next () {
			if (!hasNext()) throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int t = readByte();
			while (isPrintable(t)) {
				sb.appendCodePoint(t);
				t = readByte();
			}
			return sb.toString();
		}
		public String[] nextArray (int n) {
			String[] ar = new String[n];
			for (int i=0; i<n; i++) ar[i] = next();
			return ar;
		}
		public int nextInt () {return Math.toIntExact(nextLong());}
		public int[] nextIntArray (int n) {
			int[] ar = new int[n];
			for (int i=0; i<n; i++) ar[i] = nextInt();
			return ar;
		}
		public long nextLong () {
			if (!hasNext()) throw new NoSuchElementException();
			boolean minus = false;
			int temp = readByte();
			if (temp == '-') {
				minus = true;
				temp = readByte();
			}
			if (temp<'0' || '9'<temp) throw new NumberFormatException();
			long n = 0;
			while (isPrintable(temp)) {
				if ('0'<=temp && temp<='9') {
					n *= 10;
					n += temp - '0';
				}
				else throw new NumberFormatException();
				temp = readByte();
			}
			return minus? -n : n;
		}
		public double nextDouble () {
			return Double.parseDouble(next());
		}
		public void close () {
			try {in.close();}
			catch(Exception e){}
		}
	}

}