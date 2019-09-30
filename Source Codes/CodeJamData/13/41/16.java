import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.*;



import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  


public class A {
	static final int THREADS = 32;
	static class Sol implements Runnable{
		
		boolean started = false;
		Scanner scan;
		int caseN;
		
		int intLine(){
			return parseInt(scan.nextLine());
		}
		
		long cost(long dist){
			return dist * N - dist *(dist-1)/2;
		}
		
		long res = 0;
		int N;
		int[] P;
		long[] en;
		long[] ex;
		long origRes =0;
		long mod = 1000002013;
		void readInput() {
			N = scan.nextInt();
			int m = scan.nextInt();
			int[][]M = new int[m][3];
			TreeSet<Integer> stops = new TreeSet<>();
			for(int i=0;i<m;i++){
				for(int j=0;j<3;j++)M[i][j]=scan.nextInt();
				stops.add(M[i][0]);stops.add(M[i][1]);
				long dist = M[i][1]-M[i][0];
				long cost = cost(dist);
				cost = BigInteger.valueOf(cost).multiply(BigInteger.valueOf(M[i][2])).mod(BigInteger.valueOf(mod)).longValue();
				origRes = (origRes + cost)%mod;
			}
			P = new int[stops.size()]; en = new long[stops.size()];ex = new long[stops.size()];
			int p =0;
			for(int stop:stops){
				P[p]= stop;
				for(int i=0;i<M.length;i++){
					if(M[i][0]==stop)en[p]+=M[i][2];
					if(M[i][1]==stop)ex[p]+=M[i][2];
				}
				p++;
			}
		}
		
		
		public void run(){
			this.res = 0;
			long[] tix = new long[P.length];
			int erl =0;
			for(int p=0;p<P.length;p++){
				erl=p;
				tix[p] += en[p];
				long e = ex[p];
				while(e>0){
					if(tix[erl]==0){
						erl--; continue;
					}
					long use = min(e, tix[erl]);
					long d = P[p]-P[erl];
					long c = cost(d);
					c = BigInteger.valueOf(c).multiply(BigInteger.valueOf(use)).mod(BigInteger.valueOf(mod)).longValue();
					
					res = (res+c)% mod;
					e-=use;
					tix[erl]-=use;
				}
			}
			res = (mod + origRes - res)%mod;
			System.err.println(caseN+" finished");
		}

		void printResult(PrintStream out) {
			out.format("Case #%d: %d\n",caseN+1, res);
		}
	}

    static Sol[] solvers;
    
    static synchronized Sol getNext() {
    	for(int i=0;i<solvers.length;i++) {
    		if(!solvers[i].started){
    			solvers[i].started = true;
    			return solvers[i];
    		}
    	}
    	return null;
    }
    
    static class Worker extends Thread {
    	public void run() {
    		while(true) {
    			Sol sol = getNext();
    			if (sol == null)break;
    			sol.run();
    		}
    	}
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
		solvers = new Sol[N];
		for(int i=0;i<solvers.length;i++) {
			solvers[i] = new Sol();
			solvers[i].scan = scan;
			solvers[i].caseN = i;
			solvers[i].readInput();
		}
		Thread[]threads = new Thread[THREADS];
		for(int i=0;i<threads.length;i++){
			threads[i]=new Worker();
			threads[i].start();
		}
		for(int i=0;i<threads.length;i++){
			threads[i].join();
		}

		for(Sol s:solvers)s.printResult(out);
		System.err.println("All done");
		
	}

}


