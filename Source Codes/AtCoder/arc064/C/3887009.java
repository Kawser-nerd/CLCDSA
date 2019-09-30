import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		double x0=sc.nextLong(),y0=sc.nextLong(),x1=sc.nextLong(),y1=sc.nextLong();
		int n=sc.nextInt();
		
		double[] a=new double[n],b=new double[n];
		double[] r=new double[n];
		for(int i=0;i<n;i++){
			a[i]=sc.nextInt();
			b[i]=sc.nextInt();
			r[i]=sc.nextDouble();
		}
		
		double[][] dist=new double[n+2][n+2];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				double d=Math.sqrt((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]))-r[i]-r[j];
				d=Math.max(d,0);
				dist[i][j]=d;
			}
		}
		for(int i=0;i<n;i++){
			dist[i][n]=Math.sqrt((a[i]-x0)*(a[i]-x0)+(b[i]-y0)*(b[i]-y0))-r[i];
			dist[i][n]=Math.max(0,dist[i][n]);
			dist[n][i]=dist[i][n];
			
			dist[i][n+1]=Math.sqrt((a[i]-x1)*(a[i]-x1)+(b[i]-y1)*(b[i]-y1))-r[i];
			dist[i][n+1]=Math.max(0,dist[i][n+1]);
			dist[n+1][i]=dist[i][n+1];
		}
		dist[n][n+1]=Math.sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
		dist[n+1][n]=dist[n][n+1];
		
		double res=dijkstra(n,n+1,dist);
		System.out.println(res);
	}
	static double dijkstra(int start,int goal,double[][] gra){
		int n=gra.length;
		double[] res=new double[n];
		Arrays.fill(res,Long.MAX_VALUE);
		res[start]=0;
		
		boolean[] ju=new boolean[n+1];
		for(int j=0;j<n;j++){
			int cur=-1;
			for(int i=0;i<n;i++){
				if(ju[i])continue;
				if(cur==-1)cur=i;
				if(res[i]<res[cur]) cur=i;
			}
			for(int i=0;i<n;i++){
				if(i==cur)continue;
				double dist=res[cur]+gra[cur][i];
				if(res[i]>dist){
					res[i]=dist;
					
				}
			}
			ju[cur]=true;
		}
		return res[goal];
	}
}