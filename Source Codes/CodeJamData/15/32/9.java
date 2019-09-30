import java.io.BufferedInputStream;

import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.*;


import static java.util.Arrays.*;
import static java.lang.Math.*;


public class B {
	
	Scanner scan;
	public B(Scanner s) {
		this.scan = s;
	}

	char[]L;
	String word;
	int[]C=new int[300];
	int kn;
	int n;
	double[][]M=new double[200][200];
	double solve(int p, int pos){
		if(pos ==n) return 0;
		double r =0;
		if(M[p][pos]!=-1)return M[p][pos];
		for(char c='A';c<='Z';c++){
			double rr = 0;
			if(C[c]==0)continue;
			double pc = 1.0*C[c]/kn;

				int bp=0;
				String pref = ""+c;
				if(word.startsWith(pref))
					{
					bp = pref.length();
					if(pref.length()==word.length()){
						rr=1;
					}
					}
				for(int i=p;i>0;i--){
					pref = L[i-1]+pref;
					if(word.startsWith(pref)){
						if(pref.length()==word.length()){
							rr=1;
						}
						bp = pref.length();
					}
				}
				rr += solve(bp,pos+1);
			r+=rr*pc;
		}
		return M[p][pos]=r;
	}
	
	int maxma(){
		for(int i=1;i<word.length();i++){
			String suff=word.substring(i);
			if(word.startsWith(suff))return i;
		}
		return word.length();
	}
	
	public String solve() {
		kn = scan.nextInt();
		int ln = scan.nextInt();
		n=scan.nextInt();
		String key= scan.next();
		word = scan.next();
		for(char c:key.toCharArray())C[c]++;
		L = word.toCharArray();
		for(char c:L)if(C[c]==0)return "0.0";
		for(double[]b:M)fill(b,-1);
		double res = solve(0,0);
		int mm = maxma();
		int left = mm;
		int maxw=1;
		int p =word.length();
		while(p+left<=n){
			maxw++;p+=left;
		}
		res = maxw-res;
		return ""+res;
	}
	int intLine(){
		return Integer.parseInt(scan.nextLine());
	}
	public static void main(String[] args) throws Exception{
		Locale.setDefault(Locale.US);
		String cn = B.class.getName();
		String sampleName = cn+"-sample.in";
		String smallName = cn+"-small-attempt0.in";
		String largeName = cn+"-large.in";
		String name = largeName;
		String outName = name.substring(0, name.indexOf('.'))+".out";
		InputStream in = new BufferedInputStream(new FileInputStream("src/"+name));
		PrintStream out = new PrintStream(new File("src/"+outName));
		//PrintStream out = System.out;
		Scanner scan = new Scanner(in);
		
		int N = Integer.parseInt(scan.nextLine());
		for(int c=1;c<=N;c++) {
			String res = new B(scan).solve();
			out.printf("Case #%d: %s\n",c, res);
			if(out != System.out)System.err.println(c + " done");
		}
		
		if(out != System.out)System.err.println("All done");
		
	}

}


