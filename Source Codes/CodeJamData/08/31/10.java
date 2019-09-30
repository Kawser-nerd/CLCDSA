
import java.util.*;
import java.io.*;

public class A {

    private static long solve(long P, long K, long[] f) {
	Arrays.sort(f);
	long t=0;
	long j=0;
	for (int i=f.length-1; i>=0; i--) {
	    t+=((j/K)+1)*f[i];
	    j++;
	}
	return t;
    }

    public static void main(String[] args) throws Exception {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int N = Integer.parseInt(br.readLine().trim());
	for (int i=0; i<N; i++) {
	    String[] s = br.readLine().trim().split(" ");
	    int P = Integer.parseInt(s[0]);
	    int K = Integer.parseInt(s[1]);
	    int L = Integer.parseInt(s[2]);
	    s = br.readLine().trim().split(" ");
	    long[] f = new long[L];
	    for (int j=0; j<L; j++) {
		f[j]=Integer.parseInt(s[j]);
	    }
	    System.out.println("Case #"+(i+1)+": "+solve(P,K,f));
	}
    }

}
