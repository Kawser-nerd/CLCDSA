import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.*;



import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  


public class A {
	
	Scanner scan;
	public A(Scanner s) {
		this.scan = s;
	}
	static final long nwd( long a, long b ){
		return b==0?a:nwd( b, a % b);
	}
	public String solve() {
		String s = scan.nextLine();
		String[]ss = s.split("/");
		long a = Long.parseLong(ss[0]);long b = Long.parseLong(ss[1]);
		long g = nwd(a,b);a/=g;b/=g;
		if(Long.bitCount(b) != 1) return "impossible";
		for(int i=1;i<40;i++){
			if(a>=b/2)return ""+i;
			b/=2;
		}
		return "";
	}
	int intLine(){
		return parseInt(scan.nextLine());
	}
	public static void main(String[] args) throws Exception{
		Locale.setDefault(Locale.US);
		String cn = A.class.getName();
		String sampleName = cn+"-sample.in";
		String smallName = cn+"-small-attempt0.in";
		String largeName = cn+"-large.in";
		String name = largeName;
		String outName = name.substring(0, name.indexOf('.'))+".out";
		InputStream in = new BufferedInputStream(new FileInputStream(name));
		PrintStream out = new PrintStream(new File(outName));
		//PrintStream out = System.out;
		Scanner scan = new Scanner(in);
		
		int N = parseInt(scan.nextLine());
		for(int c=1;c<=N;c++) {
			String res = new A(scan).solve();
			out.printf("Case #%d: %s\n",c, res);
			System.err.println(c + " done");
		}
		
		System.err.println("All done");
		
	}

}


