import static java.lang.Math.*;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.*;

public class B {
	Scanner scan;

	public B(Scanner s) {
		scan = s;
	}
	
	int intLine(){
		return Integer.parseInt(scan.nextLine());
	}
	
	
	int fill(int[] seat, int rides){
		int left =0;
		int res =0;
		for(int i=1;i<seat.length;i++){
			int diff = rides - seat[i];
			if(diff<0){
				res -=diff;
			}
			left +=diff;
			if(left < 0)return -1;
		}
		return res;
	}
	
	public String solve() {
		int n = scan.nextInt();int c = scan.nextInt();int m = scan.nextInt();
		int[]seat = new int[n+1];
		int[]cust = new int[c+1];
		int maxCust=0;
		for(int i=0;i<m;i++){
			int p = scan.nextInt();
			int b = scan.nextInt();
			cust[b]++;
			seat[p]++;
			maxCust=max(maxCust, cust[b]);
		}
		for(int res =maxCust;;res++){
			int x = fill(seat, res);
			if(x>=0){
				return res+" "+x;
			}
		}
		
	}
	
	
	public static void main(String[] args) throws Exception{
		Locale.setDefault(Locale.US);
		String cn = "src/"+B.class.getName();
		String sampleName = cn+"-sample.in";
		String smallName = cn+"-small-attempt0.in";
		String largeName = cn+"-large.in";
		
		String name = largeName;
		
		String outName = name.substring(0, name.indexOf('.'))+".out";
		InputStream in = new BufferedInputStream(new FileInputStream(name));
		PrintStream out =null;
		out = new PrintStream(new File(outName));
		if(out==null) out = System.out;
		Scanner scan = new Scanner(in);
		
		int N = Integer.parseInt(scan.nextLine());
		for(int c=1;c<=N;c++) {
			String res = new B(scan).solve();
			out.printf("Case #%d: %s\n",c, res);
			if(out!=System.out)System.err.println(c + " done");
		}
		if(out!=System.out)System.err.println("All done");
		
	}
}
