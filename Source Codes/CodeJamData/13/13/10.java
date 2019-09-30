import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class C{
	Scanner sc=new Scanner(System.in);

	int INF=1<<28;
	double EPS=1e-9;

	int caze, T;
	int r, n, m, t;
	int[][] tab;

	void run(){
		T=sc.nextInt();
		sc.nextLine();
		for(caze=1; caze<=T; caze++){
			r=sc.nextInt();
			n=sc.nextInt();
			m=sc.nextInt();
			t=sc.nextInt();
			tab=new int[r][t];
			for(int j=0; j<r; j++){
				for(int i=0; i<t; i++){
					tab[j][i]=sc.nextInt();
				}
			}
			solveSmall();
		}
	}

	void solveSmall(){
		int unique=0;
		StringBuilder sb=new StringBuilder();
		for(int[] is : tab){
			// debug(is);
			int cand=0;
			for(int num=0; num<pow(10, n); num++){
				boolean ok=true;
				int[] a=new int[n];
				String _=String.format("%0"+n+"d", num);
				for(int i=0; i<n; i++){
					a[i]=_.charAt(i)-'0';
					ok&=a[i]>=2&&a[i]<=m;
				}
				for(int i=0; i<n-1; i++){
					ok&=a[i]<=a[i+1];
				}
				if(!ok){
					continue;
				}
				// debug(num, a);
				TreeSet<Integer> set=new TreeSet<Integer>();
				for(int s=0; s<1<<n; s++){
					int mul=1;
					for(int i=0; i<n; i++){
						if((s>>i&1)==1){
							mul*=a[i];
						}
					}
					set.add(mul);
				}
				ok=true;
				for(int i : is){
					ok&=set.contains(i);
				}
				if(ok){
					// debug(num);
					cand++;
					sb.append('\n').append(num);
//					break;
				}
			}
			if(cand==1){
				unique++;
			}
			// break;
		}
		debug("unique", unique);
		answer(sb.toString());
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
		new C().run();
	}
}
