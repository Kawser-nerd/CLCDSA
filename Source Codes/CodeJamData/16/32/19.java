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
	
	
	boolean cyc(int p, boolean[][]C, boolean[]U){
		if(U[p])return true;
		U[p]=true;
		for(int q=0;q<U.length;q++)if(C[p][q] && cyc(q,C,U))return true;
		U[p]=false;
		return false;
	}
	int B;
	long count(boolean[][]C){
		long[]D = new long[B];
		D[B-1]=1;
		long p=0;
		for(int k=0;k<B-1;k++) {
			long[]ND = new long[B];
			for(int i=0;i<B;i++)for(int j=0;j<B;j++)if(C[i][j]){
				ND[i]+=D[j];
			}
			D=ND;
			p+=D[0];
		}
		return p;
	}
	
	public String solveBrut() {
		B = scan.nextInt();
		int M = scan.nextInt();
		
		int pairs =0;
		for(int i=0;i<B;i++)for(int j=i+1;j<B;j++)pairs++;
		TreeSet<Integer>AT = new TreeSet<>();
		for(int m =0;m<pow(3,pairs);m++) {
			boolean[][]C = new boolean[B][B];
			int mm =m;
			for(int i=0;i<B;i++)for(int j=i+1;j<B;j++){
				int k = mm%3;
				mm/=3;
				if(k==0)continue;
				if(k==1){
					C[i][j]=true;
				}else if(j+1!=B){
					C[j][i]=true;
				}
			}
			if(cyc(0,C,new boolean[B]))continue;
			int[]D = new int[B];
			D[B-1]=1;
			int p=0;
			for(int k=0;k<B-1;k++) {
				int[]ND = new int[B];
				for(int i=0;i<B;i++)for(int j=0;j<B;j++)if(C[i][j]){
					ND[i]+=D[j];
				}
				D=ND;
				p+=D[0];
			}

			if(p==M){
				String res = "POSSIBLE";
				for(int i=0;i<B;i++){
					res+="\n";
					for(int j=0;j<B;j++){
						if(C[i][j])res+="1";
						else res+="0";
					}
				}
				return res;
			}
			
		}
		return "IMPOSSIBLE";
	}
	public String solve() {
		B = scan.nextInt();
		long M = scan.nextLong();
		long om = M;
		boolean[][]C = new boolean[B][B];
		for(int i=1;i<B;i++)for(int j=i+1;j<B;j++){
			C[i][j]=true;
		}
		long[]D = new long[B];
		D[B-1]=1;
		for(int i=B-2;i>0;i--){
			for(int j=i+1;j<B;j++)D[i]+=D[j];
		}
		for(int i=1;i<B;i++){
			if(M>=D[i]){
				M-=D[i];
				C[0][i]=true;
			}
		}
		if(M>0)
			return "IMPOSSIBLE";
		if(count(C)!=om){
			System.err.println("ERROR");
		}
		String res = "POSSIBLE";
		for(int i=0;i<B;i++){
			res+="\n";
			for(int j=0;j<B;j++){
				if(C[i][j])res+="1";
				else res+="0";
			}
		}
		return res;
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
