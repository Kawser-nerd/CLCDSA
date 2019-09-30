import java.util.*;

class Main{
	public static void main(String[] $){
		Scanner s=new Scanner(System.in);
		
		int n=s.nextInt();
		int m=s.nextInt();
		int q=s.nextInt();
		
		int[][]d=new int[n+1][n+1];
		for(int M=0;M<m;++M) {
			int f=s.nextInt()-1,t=s.nextInt()-1;
			d[0][t]++;
			d[f+1][t]--;
		}
		
		Arrays.stream(d).forEach(o->Arrays.parallelPrefix(o,Integer::sum));
		for(int i=1;i<n;++i)
			for(int j=0;j<n;++j)
				d[i][j]+=d[i-1][j];
		
		for(int r=0;r<q;++r)
			System.out.println(d[s.nextInt()-1][s.nextInt()-1]);
	}
}