import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int[]tx=new int[2],ty=new int[2];
		tx[0]=sc.nextInt();ty[0]=sc.nextInt();
		tx[1]=sc.nextInt();ty[1]=sc.nextInt();
		int TV=sc.nextInt()*sc.nextInt();
		int n=sc.nextInt();
		int[]x=new int[n];
		int[]y=new int[n];
		for(int i=0;i<n;i++) {
			x[i]=sc.nextInt();
			y[i]=sc.nextInt();
		}
		for(int i=0;i<n;i++) {
			double kyori=0;
			for(int j=0;j<2;j++) {
				kyori+=Math.sqrt(Math.pow(Math.abs(x[i]-tx[j]),2)+Math.pow(Math.abs(y[i]-ty[j]),2));
			}
			if(kyori<=TV) {
				System.out.println("YES");
				return;
			}
		}
		System.out.println("NO");
	}
}