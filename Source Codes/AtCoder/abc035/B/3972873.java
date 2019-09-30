import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		String str=scan.next();
		int a=scan.nextInt();
		int x=0;
		int y=0;
		int q=0;
		int ans=0;
		for(int i=0;i!=str.length();i++) {
			char cha=str.charAt(i);
			if(cha=='L') {
				x-=1;
			}
			if(cha=='R') {
				x+=1;
			}
			if(cha=='U') {
				y+=1;
			}
			if(cha=='D') {
				y-=1;
			}
			if(cha=='?') {
				q++;
			}
		}
		ans=Math.abs(y)+Math.abs(x);
		if(a==1) {
			ans+=q;
			System.out.println(ans);
		}
		else if(a==2){
			if(Math.abs(y)+Math.abs(x)>=q) {
				ans-=q;
			}
			else {
				if((q-Math.abs(y)+Math.abs(x))%2==1) {
					ans=1;
				}
				else {
					ans=0;
				}
			}
			System.out.println(ans);
		}

	}
}