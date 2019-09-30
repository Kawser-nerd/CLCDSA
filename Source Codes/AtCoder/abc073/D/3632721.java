import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int INF = 100000000;
		int n = in.nextInt();
		int m = in.nextInt();
		int R = in.nextInt();
		int[] r = new int[R];
		for(int i=0;i<R;i++) {
			r[i] = in.nextInt()-1;
		}
		int[][] c = new int[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(i!=j) c[i][j] = INF;
			}
		}
		for(int i=0;i<m;i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			int cost = in.nextInt();
			c[a-1][b-1] = c[b-1][a-1] = cost;
		}
		for(int k=0;k<n;k++) {
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(c[i][j]>c[i][k]+c[k][j]) c[i][j]=c[i][k]+c[k][j];
				}
			}
		}
		int ans = Integer.MAX_VALUE;
		for(int i=0;i<R;i++) {
			List<Integer> list = new LinkedList<>();
			for(int j=0;j<R;j++) {
				if(i!=j) list.add(r[j]);
			}
			int tmp = search(c,list,r[i],0);
			if(tmp<ans) ans = tmp;
		}
		System.out.println(ans);
		in.close();
	}
	
	public static int search(int[][] c,List<Integer> list,int now,int sum) {
		if(list.size()==1) return sum+c[now][list.get(0)];
		int min = Integer.MAX_VALUE;
		for(int i=0;i<list.size();i++) {
			int next = list.remove(i);
			int tmp = search(c,list,next,sum+c[now][next]);
			list.add(i, next);
			if(tmp<min) min = tmp;
		}
		return min;
	}

}