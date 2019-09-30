import java.io.BufferedInputStream;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.*;


import static java.util.Arrays.*;
import static java.lang.Math.*;


public class A {
	
	Scanner scan;
	public A(Scanner s) {
		this.scan = s;
	}

	int w;
	int[]M;
	int mv(int c) {
		if(c==w)return w;
		if(c<w)return 0;
		if(M[c]!=-1)return M[c];
		int r = c;
		for(int i=0;i<c;i++) {
			int h = w+1;
			int ms = mv(i)+mv(c-i-1)+1;
			int b = max(ms,h);
			r = min(r, b);
		}
		return M[c]=r;
	}
	
	public String solve() {
		int r=scan.nextInt();int c = scan.nextInt();w = scan.nextInt();
		int em = (c/w)*(r-1);
		M=new int[c+1];
		fill(M,-1);
		int res = mv(c)+em;
		return ""+res;
	}
	int intLine(){
		return Integer.parseInt(scan.nextLine());
	}
	public static void main(String[] args) throws Exception{
		Locale.setDefault(Locale.US);
		String cn = A.class.getName();
		String sampleName = cn+"-sample.in";
		String smallName = cn+"-small-attempt4.in";
		String largeName = cn+"-large.in";
		String name = largeName;
		String outName = name.substring(0, name.indexOf('.'))+".out";
		InputStream in = new BufferedInputStream(new FileInputStream("src/"+name));
		PrintStream out = new PrintStream(new File("src/"+outName));
		//PrintStream out = System.out;
		Scanner scan = new Scanner(in);
		
		int N = Integer.parseInt(scan.nextLine());
		for(int c=1;c<=N;c++) {
			String res = new A(scan).solve();
			out.printf("Case #%d: %s\n",c, res);
			if(out != System.out)System.err.println(c + " done");
		}
		
		if(out != System.out)System.err.println("All done");
		
	}

}


