import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

class Main{
	static Scanner s=new Scanner(System.in);
	static int gInt(){return Integer.parseInt(s.next());}

	static int n=gInt(),a=gInt(),
			v[]=IntStream.range(0,n).map(i->gInt()-a).sorted().toArray();

	static long[][]memo=new long[n][2501];
	static {
		for(int i=0;i<n;++i)
			Arrays.fill(memo[i],-1);
	}
	static long solve(int i,int j){
		if(j>0)
			return 0;
		if(i==n) {
			return j==0?1:0;
		}
		if(memo[i][-j]!=-1) {
			return memo[i][-j];
		}
		memo[i][-j]=0;
		memo[i][-j]+=solve(i+1,j+v[i]);
		memo[i][-j]+=solve(i+1,j);
		return memo[i][-j];
	}
	public static void main(String[]$){
//		System.out.println(Arrays.toString(v));
		solve(0,0);
//		for(int i=0;i<n;++i)System.out.println(Arrays.toString(memo[i]));
		System.out.println(memo[0][0]-1);
	}
}