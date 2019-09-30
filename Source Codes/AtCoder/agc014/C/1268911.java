import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		new Main().solve();
	}
	int H,W,K;
	String[]A;
	void solve(){
		Scanner sc=new Scanner(System.in);
		int count=1;
		H=sc.nextInt();
		W=sc.nextInt();
		K=sc.nextInt(); //=???????=??????????
		A=new String[H];
		for(int i=0;i<H;i++){
			A[i]=sc.next();
		}
		int fx=-1;
		int fy=-1;
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
				if(A[i].charAt(j)=='S'){
					fx=j;
					fy=i;
				}
			}
		}
		Queue<Integer> nowq=new LinkedList<Integer>();
		nowq.add(encode(fy,fx));
		
		int[] vy=new int[]{1,0,-1,0};
		int[] vx=new int[]{0,1,0,-1};
		
		boolean[][] check=new boolean[H][W];
		
		//???K?????????
			Queue<Integer> endq=new LinkedList<Integer>();
			
			for(int i=0;i<K;i++){
				Queue<Integer> nextq=new LinkedList<Integer>();
				while(!nowq.isEmpty()){
					int now=nowq.poll();
					int y=now/1000;
					int x=now%1000;
					for(int j=0;j<4;j++){
						int ny=y+vy[j];
						int nx=x+vx[j];
					
						if(!ok(ny,nx))continue;
					
						if(check[ny][nx])continue;
					
						if(A[ny].charAt(nx)=='.' && (ny==0 || ny==H-1 || nx==0 || nx==W-1)){
							System.out.println(count);
							return;
						}
						else if(A[ny].charAt(nx)=='#' && !check[y][x]){
							endq.add(encode(y,x));
							check[y][x]=true;
						}
						else if(A[ny].charAt(nx)=='.'){
							nextq.add(encode(ny,nx));
							check[ny][nx]=true;
							endq.add(encode(ny,nx));
						}
					}
				}
				nowq=nextq;
			}
			int n=endq.size();
			
			int Min=999999999;
			for(int i=0;i<n;i++){
				int now=endq.poll();
				int y=now/1000;
				int x=now%1000;
				y=Math.min(y, H-1-y);
				x=Math.min(x, W-1-x);
				if(Min>Math.min(x, y))Min=Math.min(x, y);
			}
			if(Min%K==0)System.out.println(Min/K+1);
			else System.out.println(Min/K+2);
	}
	int encode(int y,int x){
		return y*1000+x;
	}
	boolean ok(int y,int x){
		return y>=0 && x>=0 && y<H && x<W;
	}
}