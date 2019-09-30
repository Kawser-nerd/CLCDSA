import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		new Main().solve();
	}
	
	void solve() {
		Scanner sc=new Scanner(System.in);
		int ans=0;
		int h=sc.nextInt();
		int w=sc.nextInt();
		ans+=4*2+3*(h-2+w-2)*2+4*(h-2)*(w-2);
		ans/=2;
		System.out.println(ans);
	}
}