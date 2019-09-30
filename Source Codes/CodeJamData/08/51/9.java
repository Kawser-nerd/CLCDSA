import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.*;

import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  



public class A {

	Scanner scan;
	InputStream in;
	
	int intLine(){
		return parseInt(scan.nextLine());
	}
	
	ArrayList<Integer>[]H;
	ArrayList<Integer>[]V;
	int[][]D = {{-1,0},{0,1},{1,0},{0,-1}};
	long solve(){
		long res=0;
		int l = scan.nextInt();
		String S="";
		for(int i=0;i<l;i++){
			String s = scan.next();
			int t = scan.nextInt();
			for(int j=0;j<t;j++)S+=s;
		}
		H = new ArrayList[8000];
		V = new ArrayList[8000];
		for(int i=0;i<8000;i++){
			H[i]=new ArrayList<Integer>();
			V[i]=new ArrayList<Integer>();
		}
		int x = 4000;
		int y = 4000;
		int d=0;
		char[] ss=S.toCharArray();
		for(char c:ss){
			if(c=='L')d = (d+4-1)%4;
			if(c=='R')d= (d+1)%4;
			if(c=='F'){
				int nx = x + D[d][0];
				int ny = y+ D[d][1];
				if(D[d][0]==0){
					V[min(y,ny)].add(min(x,nx));
				}else{
					H[min(x,nx)].add(min(y,ny));
				}
				x=nx;
				y=ny;
			}
		}
		BitSet B = new BitSet();
		for(int i=0;i<H.length;i++){
			if(H[i].size()==0)continue;
			Collections.sort(H[i]);
			for(int j=1;j+1<H[i].size();j+=2){
				int a = H[i].get(j);
				int b = H[i].get(j+1);
				for(int k=a;k<b;k++){
					res++;
					B.set(i*4000+k);
				}
			}
		}
		for(int i=0;i<V.length;i++){
			if(V[i].size()==0)continue;
			Collections.sort(V[i]);
			for(int j=1;j+1<V[i].size();j+=2){
				int a = V[i].get(j);
				int b = V[i].get(j+1);
				for(int k=a;k<b;k++){
					int p = k*4000+i;
					if(!B.get(p))res++;
				}
			}
		}
		
	    return res;
	}
	
	void solveAll(){
		int N = parseInt(scan.nextLine());
		for(int i=0;i<N;i++){
			long r =solve();
			System.out.format("Case #%d: %d\n",i+1,r);
		}
	}
	
	A() throws Exception{
		//in = new BufferedInputStream(new FileInputStream("A.in"));
		in = new BufferedInputStream(new FileInputStream("A-large.in"));
		scan = new Scanner(in);
	}
	
	public static void main(String[] args) throws Exception{
	    Locale.setDefault(Locale.US); 
	    new A().solveAll();
	}

}
