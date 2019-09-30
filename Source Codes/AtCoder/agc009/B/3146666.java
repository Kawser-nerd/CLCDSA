import java.util.*;

public class Main{
	static Scanner s=new Scanner(System.in);
	public static void main(String[] $){
		int n=s.nextInt();
		int[] branches=new int[n];
		int[] parent=new int[n];
		int[][] childlen=new int[n][];

		for(int i=1;i<n;++i)
			++branches[parent[i]=s.nextInt()-1];

		for(int i=0;i<n;++i)
			childlen[i]=new int[branches[i]];

		loop:
		for(int i=0;i<n;++i){
			int I=i;
			while(true){
				if(branches[I]>0)
					break;
				int r=0;
				{
					int[] c=childlen[I];
					Arrays.sort(c);
					for(int j=0,e=c.length;j<e;++j)
						r=Math.max(r,c[j]+e-j);
				}
				if(I==0){
					System.out.println(r);
					break loop;
				}
				I=parent[I];
				childlen[I][--branches[I]]=r;
			}
		}
	}
}