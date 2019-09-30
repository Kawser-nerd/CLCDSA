import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.*;

import static java.util.Arrays.*;
import static java.lang.Math.*;


public class C {
	
	Scanner scan;
	public C(Scanner s) {
		this.scan = s;
	}
	int V;
	int can(ArrayList<Integer>vals){
		boolean U[] = new boolean[V+1];
		U[0]=true;
		for(int x:vals){
			for(int i=U.length-1;i>0;i--){
				if(i-x>=0 && U[i-x])U[i]=true;
			}
		}
		for(int i=1;i<U.length;i++)if(!U[i])return i;
		return 0;
	}
	public String solveSlow() {
		int C = scan.nextInt();int D = scan.nextInt(); V = scan.nextInt();
		ArrayList<Integer>A = new ArrayList<>();
		for(int i=0;i<D;i++){
			A.add(scan.nextInt());
		}
		while(true){
			int c = can(A);
			if(c==0)break;
			A.add(c);
		}
		int res = A.size()-D;
		return ""+res;
	}
	String solve() {
	int C = scan.nextInt();int D = scan.nextInt(); V = scan.nextInt();
	ArrayList<Long>A = new ArrayList<>();
	for(int i=0;i<D;i++){
		A.add(scan.nextLong());
	}
	int res = 0;
	Collections.sort(A);
	long can = 0;
	for(int i=0;i<=A.size();i++){
		long x;
		if(i==A.size()) {
			if(can<V){
				x=can+1;
				A.add(x);
			}else break;
		}
		x = A.get(i);
		if(can+1<x){
			x=can+1;
			A.add(i, x);
		}
		can += C*x;
	}
		
	res = A.size()-D;
	return ""+res;
}
	int intLine(){
		return Integer.parseInt(scan.nextLine());
	}
	public static void main(String[] args) throws Exception{
		
		Locale.setDefault(Locale.US);
		String cn = C.class.getName();
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
			String res = new C(scan).solve();
			out.printf("Case #%d: %s\n",c, res);
			if(out != System.out)System.err.println(c + " done");
		}
		
		if(out != System.out)System.err.println("All done");
		
	}

}


