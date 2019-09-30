import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		int b[]=new int[a];
		int count=0;
		for(int i=0;i!=a;i++) {
			b[i]=scan.nextInt();
			count+=b[i];
		}
		if(count%a!=0) {
			System.out.println(-1);
		}
		else {
			int ans2=count/a;
			count=0;
			int ans=0;
			for(int i=0;i!=a;i++) {
				count+=b[i];
				if(count!=ans2*(i+1)) {
					ans++;
				}
			}
			System.out.println(ans);
		}
	}
}