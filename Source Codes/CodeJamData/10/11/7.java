//Author: Fluorine
import java.util.*;

public class A{
	public static char[][] work;
	public static int N,K;
	
	public static boolean test(int x,int y,int dx,int dy,char ch){
		for (int i=0;i<K;++i){
			int curX=x+dx*i;
			int curY=y+dy*i;
			if (curX<0) return false;
			if (curY<0) return false;
			if (curX>=N) return false;
			if (curY>=N) return false;
			if (work[curX][curY]!=ch) return false;
		}
		return true;
	}
	
	public static void main(String args[]){
		Scanner scanner=new Scanner(System.in);
		int caseNumber=scanner.nextInt();
		for (int cases=0;cases<caseNumber;++cases){
			N=scanner.nextInt();
			K=scanner.nextInt();
			String[] board=new String[N];
			for (int i=0;i<N;++i)
				board[i]=scanner.next();
			work=new char[N][N];
			for (int i=0;i<N;++i){
				int cur=N-1;
				for (int j=N-1;j>=0;--j){
					while (cur>=0&&board[i].charAt(cur)=='.') --cur;
					if (cur>=0){
						work[i][j]=board[i].charAt(cur);
						--cur;
					}
					else work[i][j]='.';
				}
			}
			/*for (int i=0;i<N;++i){
				for (int j=0;j<N;++j)
					System.out.print(work[i][j]);
				System.out.println();
			}*/
			boolean redwin=false;
			boolean bluewin=false;
			for (int i=0;i<N;++i)
				for (int j=0;j<N;++j){
					if (work[i][j]=='R'){
						if (test(i,j,0,1,'R')) redwin=true;
						if (test(i,j,1,0,'R')) redwin=true;
						if (test(i,j,1,1,'R')) redwin=true;
						if (test(i,j,1,-1,'R')) redwin=true;
					}
					else if (work[i][j]=='B'){
						if (test(i,j,0,1,'B')) bluewin=true;
						if (test(i,j,1,0,'B')) bluewin=true;
						if (test(i,j,1,1,'B')) bluewin=true;
						if (test(i,j,1,-1,'B')) bluewin=true;
					}
				}
			if ((redwin)&&(bluewin)) System.out.println("Case #"+(cases+1)+": Both");
			if ((!redwin)&&(bluewin)) System.out.println("Case #"+(cases+1)+": Blue");
			if ((redwin)&&(!bluewin)) System.out.println("Case #"+(cases+1)+": Red");
			if ((!redwin)&&(!bluewin)) System.out.println("Case #"+(cases+1)+": Neither");
		}
	}
}