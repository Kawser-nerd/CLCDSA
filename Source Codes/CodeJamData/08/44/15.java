import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.*;

import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  



public class D {

	Scanner scan;
	InputStream in;
	int k;
	int intLine(){
		return parseInt(scan.nextLine());
	}
	
	
	int count (String s){
		int r =1;
		for(int i=1;i<s.length();i++){
			if(s.charAt(i)!=s.charAt(i-1))r++;
		}
		return r;
	}
	
	String trans(String s, int[]p){
		char[] r = new char[s.length()];
		for(int st =0;st<s.length();st+=k){
			for(int i=0;i<p.length;i++){
				r[st+p[i]]=s.charAt(st+i);
			}
		}
		return new String(r);
	}
	
	long solve(){
		long res=1000;
		 k = parseInt(scan.nextLine());
		String s = scan.nextLine();
		PerInt per = new PerInt(k);
		
		do{
			
			String ns = trans(s,per.St);
			per.next();
			res = min(res, count(ns));
		}while(per.hasNext());
		
	    return res;
	}
	
	void solveAll(){
		int N = parseInt(scan.nextLine());
		for(int i=0;i<N;i++){
			long r =solve();
			System.out.format("Case #%d: %d\n",i+1,r);
		}
	}
	
	D() throws Exception{
		in = new BufferedInputStream(new FileInputStream("D-small-attempt0.in"));
		//in = new BufferedInputStream(new FileInputStream("D.in"));
		scan = new Scanner(in);
	}
	
	public static void main(String[] args) throws Exception{
	    Locale.setDefault(Locale.US); 
	    new D().solveAll();
	}
	
	class PerInt {
		int[] St;
		public PerInt( int n){
			St = new int[n];
			for( int i = 0; i < St.length; i++ ) St[i] = i;
		}
		public int[] next(){		
			int j = St.length - 1;
			while( j > 0 && St[j] < St[j-1] )j--;
			if( j > 0 ){
				int k = j - 1;
				int x = St[k];
				j = St.length - 1;
				while( St[j] < x) j--;
				St[k] = St[j];
				St[j] = x;
				for( j = 0; j < (St.length-k)/2;j++ ){
					x = St[k+1+j];
					St[k+1+j] = St[St.length-1 -j];
					St[St.length-j-1] = x;
				}
			}
			else St = null;
			return St;	
		}
		public boolean hasNext(){
			return St != null;
		}
	}

}
