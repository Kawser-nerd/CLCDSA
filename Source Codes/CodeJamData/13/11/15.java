import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class A{
	Scanner sc=new Scanner(System.in);

	int INF=1<<28;
	double EPS=1e-9;

	int caze, T;
	long r, t;

	void run(){
		T=sc.nextInt();
		sc.nextLine();
		for(caze=1; caze<=T; caze++){
			r=sc.nextLong();
			t=sc.nextLong();
			solveSmall();
		}
	}

	void solveSmall(){
		long left=0, right=(long)1e18;
		for(; right-left>1;){
			long mid=(left+right)/2;
			// boolean ok=(double)mid*(2*mid+2*r-1)<=t;
			boolean ok=(2*mid+2*r-1)<=t/mid;
			if(ok){
				left=mid;
			}else{
				right=mid;
			}
		}
		answer(""+left);
	}

	void solveLarge(){

	}

	void answer(String s){
		println("Case #"+caze+": "+s);
	}

	void println(String s){
		System.out.println(s);
	}

	void print(String s){
		System.out.print(s);
	}

	void debug(Object... os){
		System.err.println(deepToString(os));
	}

	public static void main(String[] args){
		new A().run();
	}
}
