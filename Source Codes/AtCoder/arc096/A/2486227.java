import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int x = sc.nextInt();
		int y = sc.nextInt();
		int min = (int)Math.min(x,y);
		int ans = (int)Math.min(a+b, c*2)*min;
		ans += (int)Math.min(a*(x-min),2*c*(x-min)) + (int)Math.min(b*(y-min),2*c*(y-min));
		System.out.println(ans);
	}
}