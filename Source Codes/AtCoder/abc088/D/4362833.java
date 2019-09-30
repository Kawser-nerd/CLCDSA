import java.util.Scanner;
import java.util.ArrayDeque;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		char[][] a = new char[h][w];
		int[][] b = new int[h][w];
		long black=0;
		ArrayDeque<int[]> queueh = new ArrayDeque<>();
		for(int i = 0; i<h; i++){
			String c = sc.next();
			for(int j = 0; j<w; j++){
				a[i][j]=c.charAt(j);
				if(a[i][j]=='#'){
					black++;
				}
			}
		}
		int[] start = {0,0};
		b[0][0]=1;
		queueh.add(start);
		while(a[h-1][w-1]!='#' && !queueh.isEmpty()){
			int[] now = queueh.poll();
			int i = now[0];
			int j = now[1];
			if(i!=h-1 && a[i+1][j]!='#'){
				int[] tmp = {i+1,j};
				queueh.add(tmp);
				b[i+1][j]=b[i][j]+1;
				a[i+1][j]='#';
			}
			if(i!=0 && a[i-1][j]!='#'){
				int[] tmp = {i-1,j};
				queueh.add(tmp);
				b[i-1][j]=b[i][j]+1;
				a[i-1][j]='#';
			}
			if(j!=w-1 && a[i][j+1]!='#'){
				int[] tmp = {i,j+1};
				queueh.add(tmp);
				b[i][j+1]=b[i][j]+1;
				a[i][j+1]='#';
			}
			if(j!=0 && a[i][j-1]!='#'){
				int[] tmp = {i,j-1};
				queueh.add(tmp);
				b[i][j-1]=b[i][j]+1;
				a[i][j-1]='#';
			}
			
		}
		if(a[h-1][w-1]!='#'){
			System.out.println(-1);
			return;
		}
		System.out.println(h*w-b[h-1][w-1]-black);
	}
}