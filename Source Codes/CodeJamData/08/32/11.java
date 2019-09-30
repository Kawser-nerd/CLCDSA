

import java.util.*;
import java.io.*;
import java.math.*;


public class B {

    private static BigDecimal helper(BigDecimal[][][][][] d, String s, int start, int r2, int r3, int r5, int r7) {
	if (d[start][r2][r3][r5][r7]!=null) {
	    return d[start][r2][r3][r5][r7];
	}
	d[start][r2][r3][r5][r7] = BigDecimal.ZERO;
	int m2=0,m3=0,m5=0,m7=0;
	for (int i=start; i<s.length(); i++) {
	    m2=(m2*10+(s.charAt(i)-'0'))%2;
	    m3=(m3*10+(s.charAt(i)-'0'))%3;
	    m5=(m5*10+(s.charAt(i)-'0'))%5;
	    m7=(m7*10+(s.charAt(i)-'0'))%7;
	    if (i<s.length()-1) {
		d[start][r2][r3][r5][r7] = d[start][r2][r3][r5][r7].add(helper(d,s,i+1,
									       (r2-m2+2)%2,
									       (r3-m3+3)%3,
									       (r5-m5+5)%5,
									       (r7-m7+7)%7));
		d[start][r2][r3][r5][r7] = d[start][r2][r3][r5][r7].add(helper(d,s,i+1,
									       (m2-r2+2)%2,
									       (m3-r3+3)%3,
									       (m5-r5+5)%5,
									       (m7-r7+7)%7));
	    }
	    else {
		if (m2==r2 || m3==r3 || m5==r5 || m7==r7) {
		    d[start][r2][r3][r5][r7] = d[start][r2][r3][r5][r7].add(BigDecimal.ONE);
		}
	    }
	}
	return d[start][r2][r3][r5][r7];
    }

    private static BigDecimal solve(String s) {
	BigDecimal[][][][][] d = new BigDecimal[s.length()][2][3][5][7];
	return helper(d,s,0,0,0,0,0);
    }

    public static void main(String[] args) throws Exception {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int N = Integer.parseInt(br.readLine().trim());
	for (int i=0; i<N; i++) {
	    String s = br.readLine().trim();
	    System.out.println("Case #"+(i+1)+": "+solve(s));
	}
    }

}
