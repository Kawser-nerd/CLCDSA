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


public class C {
	static final int THREADS = 32;
	static class Sol implements Runnable{
		
		boolean started = false;
		Scanner scan;
		int caseN;
		
		int intLine(){
			return parseInt(scan.nextLine());
		}
		
		
		int[] res = null;
		int n;
		int[]A;
		int[]B;
		void readInput() {
			n = scan.nextInt();
			A = new int[n];
			B = new int[n];
			for(int i=0;i<n;i++)A[i]=scan.nextInt();
			for(int i=0;i<n;i++)B[i]=scan.nextInt();
		}
		
		boolean checkB(int[]P){
			for(int i=0;i<P.length;i++){
				int x = P[i];
				boolean ok = true;
				boolean hasVal = false;
				if(B[i]==1)hasVal = true;
				for(int j=i+1;j<P.length;j++){
					if (B[j]==B[i]-1 && P[i]>P[j])hasVal = true;
					if(P[j]<P[i] && B[j]>=B[i])ok = false;
				}
				if(!ok || !hasVal)return false;
			}
			return true;
		}
		
		void genA(int[] P, int p, boolean[] U) {


			if(p==P.length){
				if(!checkB(P))return;
				res = P;
				
				return;
			}
			int a = A[p];
			for (int x = 1; x <= n; x++) {
				if(res !=null)return;
				if(U[x])continue;
				boolean ok = true;
				boolean hasVal = false;

				if (a == 1)
					hasVal = true;
				for (int i = 0; i < p; i++) {
					if (A[i] == A[p] - 1) {
						if(P[i] <x)hasVal = true;
					}
					if(P[i] <x && A[i]>=a)ok = false;
				}
				if(ok && hasVal){
					P[p]=x;
					U[x]=true;
					genA(P,p+1,U);
					U[x]=false;
				}
			}
		}
		
		public void run(){
			
			genA(new int[n], 0, new boolean[n+1]);
			System.err.println(caseN+" finished");
		}

		void printResult(PrintStream out) {
			out.format("Case #%d:",caseN+1);
			for(int i=0;i<res.length;i++)out.print(" "+res[i]);
			out.println();
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
		String cn = C.class.getName();
		String sampleName = cn+"-sample.in";
		String smallName = cn+"-small-attempt0.in";
		String largeName = cn+"-large.in";
		String name = smallName;
		String outName = name.substring(0, name.indexOf('.'))+".out";
		InputStream in = new BufferedInputStream(new FileInputStream(name));
		//PrintStream out = new PrintStream(new File(outName));
		PrintStream out = System.out;
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


