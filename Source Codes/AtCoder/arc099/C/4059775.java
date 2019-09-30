import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt();
		int[][] table=new int[n][n];
		for(int i=0;i<m;i++){
			int a=sc.nextInt()-1,b=sc.nextInt()-1;
			table[a][b]++;
			table[b][a]++;
		}
		for(int i=0;i<n;i++) table[i][i]++;
		
		int cent=0;
		int[][] ad=new int[n][];
		for(int i=0;i<n;i++){
			int count=0;
			for(int j=0;j<n;j++){
				if(table[i][j]==0) count++;
			}
			if(count==0) cent++;
			ad[i]=new int[count];
			for(int j=0;j<n;j++){
				if(table[i][j]==0) ad[i][--count]=j;
			}
		}
		
		long[] hand=new long[n],other=new long[n];
		int con=0;
		int prev=-1;
		int[] stack=new int[n+m];
		int[] color=new int[n];
		Arrays.fill(color,-1);
		while(true){
			int root=-1;
			label:
			for(int i=prev+1;i<n;i++){
				if(color[i]!=-1) continue;
				root=i;
			}
			
			if(root==-1) break;
			int size=0;
			stack[size++]=root;
			color[root]=0;
			int[] bun=new int[2];
			while(size>0){
				int cur=stack[--size];
				int col=color[cur];
				for(int ch:ad[cur]){
					if(color[ch]!=-1){
						if(color[ch]!=(col^1)){
							System.out.println(-1);
							return;
						}
						continue;
					}
					color[ch]=col^1;
					stack[size++]=ch;
				}
				bun[col]++;
			}
			
			hand[con]=bun[0];
			other[con]=bun[1];
			con++;
		}
		
		hand=Arrays.copyOf(hand,con);
		other=Arrays.copyOf(other,con);
		//System.out.println(Arrays.toString(hand));
		//System.out.println(Arrays.toString(other));
		
		int[][] dp=new int[con][n*2+1];
		dp[0][(int)(Math.abs(hand[0]-other[0]))]++;
		for(int i=1;i<con;i++){
			for(int j=0;j<=n;j++){
				int dist=(int)Math.abs(hand[i]-other[i]);
				if(j>=dist){
					if(dp[i-1][j-dist]>0) dp[i][j]=1;
				}else{
					if(dp[i-1][dist-j]>0) dp[i][j]=1;
				}
				if(dp[i-1][j+dist]>0) dp[i][j]=1;
			}
			//System.out.println(Arrays.toString(dp[i]));
		}
		
		int sa=0;
		for(int i=0;i<=n;i++) if(dp[con-1][i]>0){
			sa=i;
			break;
		}
		//System.out.println(sa);
		
		long taka=(n+sa)/2,hasi=(n-sa)/2;
		long res=taka*(taka-1)/2+hasi*(hasi-1)/2;
		System.out.println(res);
	}
}