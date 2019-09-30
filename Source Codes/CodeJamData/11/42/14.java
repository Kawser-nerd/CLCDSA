package gcj2011.r2;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;

public class BLarge {
	static String BASEPATH = "x:\\gcj\\2011r2\\";
	static boolean LARGE = true;
	static String INPATH = BASEPATH + BLarge.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	public void call()
	{
		int r = ni();
		int c = ni();
		int d = ni();
		long[][] w = new long[r][c];
		for(int i = 0;i < r;i++){
			char[] cc = in.next().toCharArray();
			for(int j = 0;j < c;j++){
				w[i][j] = cc[j] - '0' + d;
			}
		}
		
		long[][] wrsums = new long[r][c+1];
		long[][] wrrsums = new long[r][c+1];
		long[][] wrcsums = new long[r][c+1];
		for(int i = 0;i < r;i++){
			for(int j = 0;j < c;j++){
				wrcsums[i][j+1] = wrcsums[i][j] + j*w[i][j];
				wrrsums[i][j+1] = wrrsums[i][j] + i*w[i][j];
				wrsums[i][j+1] = wrsums[i][j] + w[i][j];
			}
		}
		long[][] wrectsums = new long[r+1][c+1];
		long[][] wrrectsums = new long[r+1][c+1];
		long[][] wcrectsums = new long[r+1][c+1];
		for(int i = 0;i < r;i++){
			for(int j = 0;j <= c;j++){
				wcrectsums[i+1][j] = wcrectsums[i][j] + wrcsums[i][j];
				wrrectsums[i+1][j] = wrrectsums[i][j] + wrrsums[i][j];
				wrectsums[i+1][j] = wrectsums[i][j] + wrsums[i][j];
			}
		}
		
		int max = 0;
		for(int i = 0;i < r;i++){
			for(int j = 0;j < c;j++){
				for(int k = 3;i + k <= r && j + k <= c;k++){
					long wrsum = wrrectsums[i+k-1+1][j+k-1+1] - wrrectsums[i+k-1+1][j-1+1] - wrrectsums[i-1+1][j+k-1+1] + wrrectsums[i-1+1][j-1+1];
					long wcsum = wcrectsums[i+k-1+1][j+k-1+1] - wcrectsums[i+k-1+1][j-1+1] - wcrectsums[i-1+1][j+k-1+1] + wcrectsums[i-1+1][j-1+1];
					long wsum = wrectsums[i+k-1+1][j+k-1+1] - wrectsums[i+k-1+1][j-1+1] - wrectsums[i-1+1][j+k-1+1] + wrectsums[i-1+1][j-1+1];
					wrsum -= i*w[i][j] + (i+k-1)*w[i+k-1][j] + i*w[i][j+k-1] + (i+k-1)*w[i+k-1][j+k-1];
					wcsum -= j*w[i][j] + j*w[i+k-1][j] + (j+k-1)*w[i][j+k-1] + (j+k-1)*w[i+k-1][j+k-1];
					wsum -= w[i][j] + w[i+k-1][j] + w[i][j+k-1] + w[i+k-1][j+k-1];
					if(2*wrsum == (2*i+k-1)*wsum && 2*wcsum == (2*j+k-1)*wsum){
						max = Math.max(max, k);
					}
				}
			}
		}
		if(max == 0){
			out.println("IMPOSSIBLE");
		}else{
			out.println(max);
		}
	}
	
	Scanner in;
	PrintWriter out;
	
	public BLarge(Scanner in, PrintWriter out)
	{
		this.in = in;
		this.out = out;
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
	
	public static void main(String[] args) throws Exception
	{
		long start = System.currentTimeMillis();
		
		Scanner in = INPUT.isEmpty() ? new Scanner(new File(INPATH)) : new Scanner(INPUT);
		PrintWriter out = INPUT.isEmpty() ? new PrintWriter(new File(OUTPATH)) : new PrintWriter(System.out);
		int n = in.nextInt();
		in.nextLine();
		
		for(int i = 0;i < n;i++){
			out.printf("Case #%d: ", i+1);
			new BLarge(in, out).call();
			out.flush();
			if(INPUT.isEmpty())System.err.println("case " + (i + 1) + " solved.\t");
		}
		
		long end = System.currentTimeMillis();
		System.out.println((end - start) + "ms");
	}
}
