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
	
	int intLine(){
		return parseInt(scan.nextLine());
	}
	
	long solve(){
		long res=0;
		int H = scan.nextInt();
		int W = scan.nextInt();
		int R = scan.nextInt();
		int[][]D = new int[H][W];
		boolean[][]X = new boolean[H][W];
		D[0][0]=1;
		for(int i=0;i<R;i++){
			int x = scan.nextInt()-1;
			int y = scan.nextInt()-1;
			if(x<0 ||y<0)continue;
			if(x+1>=H || y+1>=W)continue;
			X[x][y]=true;
		}
		for(int x =0;x<H;x++)for(int y=0;y<W;y++){
			if(X[x][y])continue;
			int px = x-2;
			int py = y-1;
			if(px>=0 && py>=0){
				D[x][y]=(D[x][y]+D[px][py])%10007;
			}
			px = x-1;
			py=y-2;
			if(px>=0 && py>=0){
				D[x][y]=(D[x][y]+D[px][py])%10007;
			}
		}
	    return D[H-1][W-1];
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

}
