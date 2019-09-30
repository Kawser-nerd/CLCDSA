/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package javaapplication1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.math.BigInteger;
import java.util.Locale;

/**
 *
 * @author codejam
 */



public class Main implements Runnable {
	StreamTokenizer st;

	int nextInt() throws Exception {
		st.nextToken();
		return (int)st.nval;
	}

	void solve() throws Exception {
		Locale.setDefault(Locale.US); // necessary for floats I/O

//		Scanner in = new Scanner(new File("a.in"));
//		Scanner in = new Scanner(new InputStreamReader(System.in));
//		usage: in.nextIn() and so on. SLOW !!!

//		st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		st = new StreamTokenizer(new BufferedReader(new FileReader("1.in")));

		PrintWriter out = new PrintWriter("1.out");
		int t = nextInt();
                for(int test=1; test<=t; ++test){
                    int d=nextInt();
                    int n=nextInt();
                    int[][] a=new int[n][];
                    for(int i=0; i<n; ++i){
                        a[i]=new int[nextInt()];
                        a[i][0]=0;
                        for(int j=1; j<a[i].length; ++j){
                            a[i][j]=nextInt()-1;
                        }
                    }
                    BigInteger m=BigInteger.valueOf(0);
                    for(int i=0; i<n; ++i){
                        for(int j=0; j<a[i].length; ++j){
                            if(a[i][j]>=d) continue;
                            m=m.add(BigInteger.valueOf(d-a[i][j]).
                                    multiply(BigInteger.valueOf(d).pow(n-1)));
                            for(int i1=0; i1<i; ++i1){
                                BigInteger mult=BigInteger.valueOf(d).pow(n-2);
                                mult=mult.multiply(BigInteger.valueOf(2));
                                for(int j1=0; j1<a[i1].length; ++j1){
                                    int x=Math.max(d-Math.max(a[i][j], a[i1][j1]), 0);
                                    m=m.add(BigInteger.valueOf(x).
                                            multiply(mult));
                                }
                            }
                        }
                    }
//                    out.println("Case #"+test+": "+m.toString()+"/"+
//                            BigInteger.valueOf(d).pow(n).toString());
                    BigInteger K, A, B;
                    B=BigInteger.valueOf(d).pow(n);
                    BigInteger[] arr=m.divideAndRemainder(B);
                    K=arr[0];
                    A=arr[1];
                    BigInteger g=A.gcd(B);
                    A=A.divide(g);
                    B=B.divide(g);
                    out.println("Case #"+test+": "+K.toString()+"+"+
                            A.toString()+"/"+B.toString());
                }
		out.flush(); //  !!!
	}

	@Override
	public void run() {
		try {
			solve();
		}
		catch (Exception e) {
			e.printStackTrace();
			throw new IllegalStateException();
		}

	}
	public static void main(String[] args) {
		new Thread(new Main()).run();
	}
}
