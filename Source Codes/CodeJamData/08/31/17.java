import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.io.*;
import java.util.*;


public class TaskA implements Runnable {

    private static PrintWriter pw = null;
    private static BufferedReader br = null;
    private static StringTokenizer stk = null;
   
    public static boolean tknize(){
        try {
        	String s = br.readLine();
            stk = new StringTokenizer(s);
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }
   
    public static Integer ni(){
    	while (stk==null||!stk.hasMoreTokens()) tknize();
        return Integer.valueOf(stk.nextToken());
    }

    public static long nl(){
    	while (stk==null||!stk.hasMoreTokens()) tknize();
        return Long.valueOf(stk.nextToken());
    }    
    
    public static double nd(){
    	while (stk==null||!stk.hasMoreTokens()) tknize();
        return Double.valueOf(stk.nextToken());
    }
   
   
    public static void main(String[] args) throws FileNotFoundException {
    	new Thread(new TaskA()).start();
    }
    
   

	@Override
	public void run() {
        try {
			pw = new PrintWriter("a.out");
			br = new BufferedReader(new FileReader("a.in"));
			tknize();
			int N = ni();
			for (int ts=0;ts<N;ts++) {
				long P = ni();
				long k = ni();
				int l = ni();
				long[] a = new long[l];
				for (int i=0;i<l;i++)
					a[i] = ni();
				Arrays.sort(a);
				long p = 0;
				long sh = 0;
				long s = 0;
				for (int i=l-1;i>=0;i--) {
					if (p==k) {p=0;sh++;}
					s+=a[i]*(sh+1);
					p++;
				}
				pw.println("Case #"+(ts+1)+": "+s);
			}
			pw.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}