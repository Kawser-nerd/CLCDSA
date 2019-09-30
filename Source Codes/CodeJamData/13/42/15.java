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


public class B {
	static final int THREADS = 1;
	static class Sol implements Runnable{
		
		boolean started = false;
		Scanner scan;
		int caseN;
		
		int intLine(){
			return parseInt(scan.nextLine());
		}
		
		
		long[] res = new long[2];
		long n,p;
		void readInput() {
			n = scan.nextInt();
			p = scan.nextLong();
		}
		
		String toBin(long x){
			String s = Long.toBinaryString(x);
			while(s.length()<n)s = "0"+s;
			return s;
		}
		
		boolean canWin(long x){
			
			long tot = (1L <<n);
			long fw = tot-x-1;
			
			String P = toBin(p-1);
			for(int i=0;i<n;i++){
				if(P.charAt(i)=='1'){
					if(fw>0)return true;
					boolean az = true;
					for(int j=i+1;j<n;j++)if(P.charAt(j)=='0')az = false;
					return az;
				} else{
					if(fw==0)return false;
					fw --;
					fw /=2;
				}
			}
			return true;
		}
		
		boolean canLose(long x){
			long gt = x;

			String P = toBin(p-1);
			for(int i=0;i<n;i++){
				if(P.charAt(i)=='1'){
					if(gt ==0)return false;
					gt --;
					gt = gt/2;
				} else {
					if(gt>0)return true;
					return false;
				}
			}
			
			return false;
		}
		
		public void run(){
			long tot = (1L <<n);
			    long a = 0;
		        long b =tot;
		        while(b!=a){
		            long c = a+(b-a)/2;
		            if(canWin(c)){
		                a=c+1;
		            }else b=c;
		        }
		    res[1]= a-1;
		    
		    a = 0;
		    b = tot;
	        while(b!=a){
	            long c = a+(b-a)/2;
	            if(!canLose(c)){
	                a=c+1;
	            }else b=c;
	        }
	        res[0]=a-1;
			/*
			for(long p =tot-1 ;p>0;p--){
				if(canWin(p)){
					res[1]=p;
					break;
				}
			}
			for(long p=0;p<tot;p++){
				if(canLose(p)){
					res[0]=p-1;break;
				}
			}*/
			System.err.println(caseN+" finished");
		}

		void printResult(PrintStream out) {
			out.format("Case #%d: %d %d\n",caseN+1, res[0], res[1]);
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
		String cn = B.class.getName();
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


