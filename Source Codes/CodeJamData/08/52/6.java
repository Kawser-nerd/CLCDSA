import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.*;

import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  



public class B {

	Scanner scan;
	InputStream in;
	
	int intLine(){
		return parseInt(scan.nextLine());
	}
	LinkedList<int[]>Q;
	int[][][][]B;
	void add(int x,int y, int px, int py, int time){
		if(B[x][y][px][py]>time){
			B[x][y][px][py]=time;
			Q.add(new int[]{x,y,px,py});
		}
	}
	
	long solve(){
		long res=0;
		int R = scan.nextInt();
		int C = scan.nextInt();
		char[][]M = new char[R+2][C+2];
		for(int i=1;i<=R;i++){
			String s = scan.next();
			s = "#"+s+"#";
			M[i]=s.toCharArray();
		}
		C+=2;R+=2;
		for(int i=0;i<C;i++){
			M[0][i]=M[R-1][i]='#';
		}
		int sx=0;int sy=0;
		for(int i=0;i<R;i++)for(int j=0;j<C;j++){
			if(M[i][j]=='O'){
				sx=i;sy=j;
			}
		}
		B = new int[R][C][R][C];
		for(int a[][][]:B)for(int[][]b:a)for(int[]c:b)fill(c,100000);
		Q = new LinkedList<int[]>();
		Q.add(new int[]{sx,sy,sx,sy});
		B[sx][sy][sx][sy]=0;
		res =10000;
		while(Q.size()>0){
			int[]q = Q.removeFirst();
			int x = q[0],y=q[1],px=q[2],py=q[3];
			int t = B[x][y][px][py];
			if(M[x][y]=='X')res=min(res,t);
			for(int i=-1;i<2;i++)for(int j=-1;j<2;j++){
				if(abs(i)+abs(j)!=1)continue;
				int nx =x+i;
				int ny=y+j;
				if(M[nx][ny]=='#'){
					add(px,py,px,py,t+1);
				}else{
					add(nx,ny,px,py,t+1);
				}
				nx=x;ny=y;
				while(M[nx+i][ny+j] !='#'){
					nx+=i;ny+=j;
				}
				add(x,y,nx,ny,t);
			}
		}
	    return res;
	}
	
	void solveAll(){
		int N = parseInt(scan.nextLine());
		for(int i=0;i<N;i++){
			long r =solve();
			if(r==10000)System.out.format("Case #%d: THE CAKE IS A LIE\n",i+1);
			else System.out.format("Case #%d: %d\n",i+1,r);
		}
	}
	
	B() throws Exception{
		//in = new BufferedInputStream(new FileInputStream("B.in"));
		in = new BufferedInputStream(new FileInputStream("B-large.in"));
		scan = new Scanner(in);
	}
	
	public static void main(String[] args) throws Exception{
	    Locale.setDefault(Locale.US); 
	    new B().solveAll();
	}

}
