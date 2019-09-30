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
		
		
		int res = 0;
		int n, m, k;
		
		boolean run(int x,int y, boolean[][]m, boolean[][]u){
			if(u[x][y] || m[x][y])return false;
			u[x][y]=true;
			if(x==0 || y==0 || x+1==m.length||y+1==m[0].length)return true;
			for(int i=-1;i<2;i++)for(int j=-1;j<2;j++){
				if(i*j!=0)continue;
				if(run(x+i, y+j, m,u))return true;
			}
			return false;
		}
		
		int count(boolean[][]m){
			int res =0;
			for(int i=0;i<m.length;i++)for(int j=0;j<m[0].length;j++){
				if(!run(i,j,m, new boolean[m.length][m[0].length]))res++;
			}
			return res;
		}
		
		void readInput() {
			n = scan.nextInt();
			m = scan.nextInt();
			k = scan.nextInt();
		}
		
		
		public void run(){
			this.res = 0;
			res = k;
			for(int q=0;q<(1<<(n*m));q++){
				boolean[][]b = new boolean[n][m];
				int w=0;
				for(int i=0;i<n;i++)for(int j=0;j<m;j++){
					if((q&(1<<w))!=0)b[i][j]=true;
					w++;
				}
				if(count(b)>=k)res = min(res, Integer.bitCount(q));
			}
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
		String cn = C.class.getName();
		String sampleName = cn+"-sample.in";
		String smallName = cn+"-small-attempt1.in";
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


