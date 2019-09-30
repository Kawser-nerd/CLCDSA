import static java.lang.Math.*;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.*;

public class A {
	Scanner scan;

	public A(Scanner s) {
		scan = s;
	}
	
	int intLine(){
		return Integer.parseInt(scan.nextLine());
	}
	
	int [][][][]M;
	int P;
	int doit(int r,int p1,int p2,int p3) {
		if(M[r][p1][p2][p3]!=-1)return M[r][p1][p2][p3];
		int res =0;
		if(p1+p2+p3==0)return 0;
		
		if(p1>0){
			int x = doit((r+1)%P,p1-1,p2,p3);
			res = max(res,x);
		}
		if(p2>0){
			int x = doit((r+2)%P,p1,p2-1,p3);
			res = max(res,x);
		}
		if(p3>0){
			int x = doit((r+3)%P,p1,p2,p3-1);
			res = max(res,x);
		}
		if(r==0) res++;
		return M[r][p1][p2][p3]=res;
	}
	
	public String solve() {
		int n = scan.nextInt();
		P = scan.nextInt();
		int[]A = new int[4];
		for(int i=0;i<n;i++){
			int x = scan.nextInt();
			A[x%P]++;
		}
		M = new int[P][A[1]+1][A[2]+1][A[3]+1];
		for(int[][][]m1:M)for(int[][]m2:m1)for(int[]m3:m2)Arrays.fill(m3,-1);
		int res =doit(0, A[1], A[2],A[3]);
		res+=A[0];
		return ""+res;
	}
	
	
	public static void main(String[] args) throws Exception{
		Locale.setDefault(Locale.US);
		String cn = "src/"+A.class.getName();
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
			String res = new A(scan).solve();
			out.printf("Case #%d: %s\n",c, res);
			if(out!=System.out)System.err.println(c + " done");
		}
		if(out!=System.out)System.err.println("All done");
		
	}
}
