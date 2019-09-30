import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.*;

import static java.util.Arrays.*;
import static java.lang.Math.*;


public class D {
	static final int THREAD_COUNT = 32;
	class Solver extends Thread {
		int testNo;
		public void run() {
			solve();
			completed(this);
		}
		
		String res = "";
		TreeMap<Integer, Integer> T = new TreeMap<Integer, Integer>();
		int sum =0;
		public void readInput(Scanner scan) {
			int p = scan.nextInt();

			int[]A = new int[p];
			for(int i=0;i<p;i++)A[i]=scan.nextInt();
			for(int i=0;i<p;i++){
				int f = scan.nextInt();
				sum+=f;
				T.put(A[i], f);
			}
		}
		
		void rem(int x, TreeMap<Integer, Integer>T){
			if(!T.containsKey(x))throw new RuntimeException("ERROR");
			int v = T.get(x);
			v--;
			if(v==0)T.remove(x);
			else T.put(x, v);
		}
		
		public void solve() {
			int n =1;
			while (1<<n !=sum)n++;
			int[]res = new int[n];
			rem(0,T);
			for(int i=0;i<n;i++) {
				int x = T.firstKey();
				res[i]=x;
				rem(x,T);
				if(i==0)continue;
				int nn = i;
				for(int m =1;m<(1<<nn);m++){
					int sum = x;
					for(int j=0;j<nn;j++){
						if(((m&(1<<j))!=0)) {
							sum+=res[j];
						}
					}
					rem(sum, T);
				}
			}
			this.res="";
			for(int i=0;i<n;i++) {
				this.res+=res[i];
				if(i+1<n)this.res+=" ";
			}
		}
		
		public String getRes() {
			return res;
		}
		
		int[] intArr(Scanner scan) {
			int n = scan.nextInt();
			int[]res = new int[n];
			for(int i=0;i<n;i++)res[i]=scan.nextInt();
			return res;
		}
		
		int intLine(Scanner scan){
			return Integer.parseInt(scan.nextLine());
		}
	}
	
	
	int testcases;
	int lastStarted=-1;
	int completed=0;
	String[]results;
	private Scanner scan;
	PrintStream out;
	
	private synchronized void completed(Solver sol) {
		results[sol.testNo]=sol.getRes();
		completed ++;
		if(out != System.out)System.err.println(sol.testNo + " done " + (testcases - completed)+ " left");
		if(lastStarted+1!=testcases) {
			startNew();
		} else if (completed == testcases) {
			printResults();
		}
	}
	
	private void printResults() {
		for(int c=0;c<testcases;c++) {	
			out.printf("Case #%d: %s\n",c+1, results[c]);
		}
		if(out != System.out)System.err.println("All done");
	}
	
	private synchronized void startNew() {
		if(lastStarted+1==testcases)return;
		Solver sol = new Solver();
		sol.testNo = ++lastStarted;
		sol.readInput(scan);
		sol.start();
	}
	
	public void doit(String[]args) throws Exception {
		Locale.setDefault(Locale.US);
		String cn = this.getClass().getName();
		String sampleName = cn+"-sample.in";
		String smallName = cn+"-small-attempt4.in";
		String largeName = cn+"-large.in";
		String name = sampleName;
		name = "src/" + name;
		String outName = name.substring(0, name.indexOf('.'))+".out";
		if(args.length>0) {
			name = args[0];
			outName = name.substring(0, name.indexOf('.'))+".out";
			out = new PrintStream(new File(outName));
		}
		InputStream in = new BufferedInputStream(new FileInputStream(name));
		//out = new PrintStream(new File("src/"+outName));
		if (out == null) out = System.out;
		scan = new Scanner(in);
		
		testcases = Integer.parseInt(scan.nextLine());
		results = new String[testcases];
		for(int i=0;i<min(THREAD_COUNT, testcases);i++)startNew();
		
	}
	
	public static void main(String[] args) throws Exception{
		new D().doit(args);
	}

}


