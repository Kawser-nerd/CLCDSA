import java.util.Scanner;
public class Main{
	static int INF=10000;
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		String ans="NO";
		int x=sc.nextInt();
		int y=sc.nextInt();
		int xg=sc.nextInt();
		int yg=sc.nextInt();
		int dist=sc.nextInt()*sc.nextInt();
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			int x2=sc.nextInt();int y2=sc.nextInt();
			double dist2=Math.sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
			dist2+=Math.sqrt((x2-xg)*(x2-xg)+(y2-yg)*(y2-yg));
			if(dist>=dist2)ans="YES";
		}
		System.out.println(ans);
	}
}