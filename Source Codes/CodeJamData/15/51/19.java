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

	class N {
		int id;
		ArrayList<N>ch = new ArrayList<A.N>();
		int s;
		int par;
		N(int i,int a, int b){id=i;s=a;par=b;}
	}
	
	int count(N p, int a, int b) {
		if(p.s<a||p.s>b)return 0;
		int res = 1;
		for(N q:p.ch)res+=count(q, a, b);
		return res;
	}
	public String solveold() {
		int n = scan.nextInt();int D = scan.nextInt();
		int s0 =scan.nextInt();int as=scan.nextInt();int cs = scan.nextInt();int rs=scan.nextInt();
		int m0=scan.nextInt();int am=scan.nextInt();int cm=scan.nextInt();int rm=scan.nextInt();
		int[]S = new int[n];int[] P = new int[n];
		S[0]=s0;P[0]=m0;
		N[]nodes = new N[n];
		nodes[0]=new N(0,s0, -1);
		for(int i=1;i<n;i++){
			S[i]= (int)((1L*S[i-1]*as+cs)%rs);
			P[i]= (int)((1L*P[i-1]*am+cm)%rm);


		}
		for(int i=1;i<n;i++){
			P[i]%=i;
			nodes[i]=new N(i,S[i], P[i]);
			nodes[P[i]].ch.add(nodes[i]);
		}
		int res = 0;
		int ba=0;int bb=0;
		for(int a=max(0,s0-D);a<=s0+D;a++){
			int r = count(nodes[0], a, a+D);
			if(r>res){
				res =r;
				ba=a;bb=a+D;
			}
		}
		System.out.println("best "+ba+" "+bb);
		return ""+res;
	}
	
	
	HashSet<Integer>included = new HashSet<Integer>();
	
	void include(N p, int a, int b) {
		if(p.s<a||p.s>b)return;
		included.add(p.id);
		for(N q:p.ch)include(q, a, b);
	}
	
	void exclude(N p, int a, int b) {
		if(p.s<a||p.s>b)return;
		included.remove(p.id);
		for(N q:p.ch)exclude(q, a, b);
	}
	
	public String solve() {
		int n = scan.nextInt();int D = scan.nextInt();
		int s0 =scan.nextInt();int as=scan.nextInt();int cs = scan.nextInt();int rs=scan.nextInt();
		int m0=scan.nextInt();int am=scan.nextInt();int cm=scan.nextInt();int rm=scan.nextInt();
		int[]S = new int[n];int[] P = new int[n];
		S[0]=s0;P[0]=m0;
		N[]nodes = new N[n];
		nodes[0]=new N(0,s0, -1);
		for(int i=1;i<n;i++){
			S[i]= (int)((1L*S[i-1]*as+cs)%rs);
			P[i]= (int)((1L*P[i-1]*am+cm)%rm);
		}
		ArrayList[] bySal = new ArrayList[rs];
		for(int i=1;i<n;i++){
			P[i]%=i;
			nodes[i]=new N(i,S[i], P[i]);
			nodes[P[i]].ch.add(nodes[i]);
			if(bySal[S[i]]==null)bySal[S[i]]=new ArrayList();
			bySal[S[i]].add(nodes[i]);
		}
		int res = 0;

		include(nodes[0], max(0,s0-D), max(0,s0-D)+D);
		res = included.size();
		for(int a=max(1,s0-D+1);a<=s0;a++){
			int b = a+D;
			if(a<bySal.length && bySal[a-1]!=null) {
				for(Object o:bySal[a-1]){
					N p = (N)o;
					if(included.contains(p.id)){
						exclude((N)o, a-1,b-1);
					}
				}
			}
			if(b<bySal.length && bySal[b]!=null) {
				for(Object o:bySal[b]){
					N p = (N)o;
					if(!included.contains(p)&& included.contains(p.par)) {
						include(p, a,b);
					}
				}
			}
			res = max(res, included.size());
		}
		return ""+res;
	}
	
	int[] intArr() {
		int n = scan.nextInt();
		int[]res = new int[n];
		for(int i=0;i<n;i++)res[i]=scan.nextInt();
		return res;
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
		String name = sampleName;
		name = "src/" + name;
		String outName = name.substring(0, name.indexOf('.'))+".out";
		PrintStream out = null;
		if(args.length>0) {
			name = args[0];
			outName = name.substring(0, name.indexOf('.'))+".out";
			out = new PrintStream(new File(outName));
		}
		InputStream in = new BufferedInputStream(new FileInputStream(name));
		//out = new PrintStream(new File("src/"+outName));
		if (out == null) out = System.out;
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


