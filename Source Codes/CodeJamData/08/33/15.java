import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.io.*;
import java.util.*;


public class TaskC implements Runnable {

    private static PrintWriter pw = null;
    private static BufferedReader br = null;
    private static StringTokenizer stk = null;
   
    public static boolean tknize(){
        try {
            stk = new StringTokenizer(br.readLine());
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
    	new Thread(new TaskC()).start();
    }
   

    final long mag = 1000000007;
	@Override
	public void run() {
        try {
			pw = new PrintWriter("a.out");
			br = new BufferedReader(new FileReader("a.in"));
			int N = ni();
			for (int ts=0;ts<N;ts++) {
				int n = ni();
				int m = ni();
				long x = ni();
				long y = ni();
				long z = ni();
				long[] a = new long[m];
				for (int i=0;i<m;i++)
					a[i]=ni();
				long[] sp = new long[n];
				for (int i=0;i<n;i++) {
					sp[i]=a[i%m];
					a[i%m]=(x*a[i%m]+y*(i+1))%z;
				}
				long[] sol = new long[n];
				for (int i=0;i<n;i++) {
					sol[i]=1;
					for (int j=0;j<i;j++)
						if (sp[i]>sp[j])
							sol[i]=(sol[i]+sol[j])%mag;
				}
				long ss = 0;
				for (int i=0;i<n;i++)
					ss=(ss+sol[i])%mag;
				pw.println("Case #"+(ts+1)+": "+ss);
			}
			pw.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}