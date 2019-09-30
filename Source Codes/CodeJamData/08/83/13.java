import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;
public class Main implements Runnable{
	
	final static String fName = "tree";
	final long MOD = 1000000009L;

	boolean[][] g;
	int n; int k;
	boolean[] gone;

	long get(int v, int num){
		//System.out.println(v + " " + num);
		gone[v] = true;
		int nv = 0;
		for(int i = 0; i < n; i++) if (g[v][i] && !gone[i]) nv++;
			//System.out.println("    " + nv);
		if ( num < nv ) return 0;
		else if (nv == 0) return 1;
		else{
			long res = 1L;
            for(int i = 0; i < n; i++) if (g[v][i] && !gone[i])
            	if (v == 0) res  = ( get(i, k - nv) * res ) % MOD;
            	else res  = ( get(i, k - 1 - nv) * res ) % MOD; 
            BigInteger cc = new BigInteger("1");
            for(int i = 0; i < nv; i++){ cc = cc.multiply( new BigInteger( Integer.toString(num-i) ) );
            //System.out.println("    " + cc.toString() + "    " + (num-i));
            } 
            //for(int i = 1; i <= nv; i++) cc = cc.divide( new BigInteger( Integer.toString(i) ) );
            cc = cc.remainder( new BigInteger( Long.toString( MOD) ) );
            long r = Long.parseLong( cc.toString() );
            res  = ( res * r ) % MOD; return res;
		}  
	}
	
	public void run(){
		try{
	    	Scanner in = new Scanner( new File( fName + ".in") );
	   		PrintWriter out = new PrintWriter( new FileWriter( new File( fName + ".out" ) ) );
	   		int tt = in.nextInt();
	   		for(int test  = 1; test <= tt; test++){
	   			n = in.nextInt();
	   			k = in.nextInt();
	   			//System.out.println(n+" "+k);
	   			g = new boolean[n][n];
	   			for(int i = 0; i < n-1; i++){
	   				int a = in.nextInt()-1; int b = in.nextInt()-1; g[a][b] = true; g[b][a] = true;
	   			}
	   			gone = new boolean[n];
	   			long res = get(0, k);
	   			out.println("Case #" + test + ": " + res);
	   		}
	   		in.close();
	   		out.close();
	   	} catch (Exception E){E.printStackTrace(); }

	}

	public static void main(String argc[]){
		try{
			new Thread( new Main() ).start();
		} catch (Exception E){E.printStackTrace(); }
	}
}