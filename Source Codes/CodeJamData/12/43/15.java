

import java.io.BufferedReader;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class GCJ_R2_C {

	static boolean test = true;

	private void solve() throws Throwable {
		int t = iread();
		for (int i = 0; i < t; i++) {
			solveIt(i+1);
		}
	}
	
	private void solveIt(int casenr) throws Throwable {
		
		int n = iread();
		int[] impression = new int[n-1];
		long[] height = new long[n];
		long max = 1000000000L;
		long min = 0L;
		long start = max/2;
		boolean impossible = false;
		
		for (int i = 0; i < n-1; i++) {
			impression[i] = iread()-1;
		}
		height[height.length-1] = start;
		height[height.length-2] = start;
		
		for (int i = impression.length-2; i >= 0; i--) {
			
			//binsearch
			int highestTop = impression[i];
			long mid = start;
			long lo = min, hi = max;
			long lastWorking = 0;
			while (hi - lo > 1) {
				mid = (hi+lo)/2;
				
				long targetDiff = (height[highestTop] - mid);
				
				boolean leftError = false;
				boolean rightError = false;
				
				for (int j = i+1; j < height.length; j++) {
					
					if(j == highestTop){
						continue;
					}
					long currentDiff =(height[j]- mid);
					long currentWay = currentDiff * (highestTop - i);
					long targetWay = targetDiff * (j - i); 
					
					if(j < highestTop && currentWay >= targetWay){
						leftError = true;
					}
					
					if (j > highestTop && currentWay >= targetWay){
						rightError = true;
					}
				}
				if(leftError && rightError){
					impossible = true;
					break;
				} else if(leftError){
					lo = mid;
				} else if(rightError){
					hi = mid;
				} else {
					lastWorking = mid;
					if(Math.abs(lo - start) > Math.abs(hi - start)){
						lo = mid;
					} else {
						hi = mid;
					}
				}
			}
			
			height[i] = lastWorking;
		}
		String ansB = "";
		
		for (int i = 0; i < n; i++) {
			ansB += height[i] + "";
			if(i < n-1){
				ansB += " ";
			}
		}
		
		if(impossible){
			ansB = "Impossible";
		}
		
		String answerString = "Case #" + casenr + ": " +ansB;
		out.write(answerString + "\n");
		System.out.println(answerString);
	}

	public int iread() throws Exception {
		return Integer.parseInt(wread());
	}

	public double dread() throws Exception {
		return Double.parseDouble(wread());
	}

	public long lread() throws Exception {
		return Long.parseLong(wread());
	}

	public String wread() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) throws Throwable {
		new GCJ_R2_C().solve();
		out.close();
	}

	public GCJ_R2_C() throws Throwable {
		if (test) {
			in = new BufferedReader(new FileReader(new File(testDataFile)));
			out = new BufferedWriter(new FileWriter(getClass().getCanonicalName() + "-out.txt"));
		} else {
			new BufferedReader(inp);
		}
	}

	static InputStreamReader inp = new InputStreamReader(System.in);
	static BufferedReader in = new BufferedReader(inp);
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
//	static BufferedWriter out;// = new BufferedWriter(new FileWriter("out.txt"));

//	static String testDataFile = "testdata.txt";
	static String testDataFile = "C-small-attempt1.in";
}