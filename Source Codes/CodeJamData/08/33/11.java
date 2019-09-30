
import java.util.*;
import java.io.*;

public class C {

    private static long helper(long[] lim, long[][] d, int cp, int started) {
	if (cp==lim.length) {
	    return 1;
	}
	if (d[cp][started]!=-1) {
	    return d[cp][started];
	}
	d[cp][started]=1;
	for (int i=cp; i<lim.length; i++) {
	    if (started==0 || lim[i]>lim[cp-1]) {
		d[cp][started] = (d[cp][started] + helper(lim,d,i+1,1))%(1000000007);
	    }
	}
	return d[cp][started];
    }


    private static long solve(long[] lim) {
	int n = lim.length;
	long[][] d = new long[n][2];
	for (int i=0; i<n; i++)
	    for (int j=0; j<2; j++)
		d[i][j]=-1;
	return helper(lim,d,0,0)-1;
    }

    public static void main(String[] args) throws Exception {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int N = Integer.parseInt(br.readLine().trim());
	for (int i=0; i<N; i++) {
	    String[] s = br.readLine().trim().split(" ");
	    int n = Integer.parseInt(s[0]);
	    int m = Integer.parseInt(s[1]);
	    long X = Long.parseLong(s[2]);
	    long Y = Long.parseLong(s[3]);
	    long Z = Long.parseLong(s[4]);
	    long[] A = new long[m];
	    for (int j=0; j<m; j++) {
		A[j]=Long.parseLong(br.readLine().trim());
	    }
	    long[] lim = new long[n];
	    for (int j=0; j<n; j++) {
		lim[j] = A[j%m];
		//System.out.println(lim[j]);
		A[j%m] = (X*A[j%m] + Y*(j + 1))%Z;
	    }
	    System.out.println("Case #"+(i+1)+": "+solve(lim));
	}
    }

}
