import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		new Main().solve();
	}
	
	void solve() {
		Scanner sc=new Scanner(System.in);
		int x1,y1,x2,y2,x3,y3,r;
		x1=sc.nextInt();
		y1=sc.nextInt();
		r=sc.nextInt();
		x2=sc.nextInt();
		y2=sc.nextInt();
		x3=sc.nextInt();
		y3=sc.nextInt();
		String ansR="YES";
		String ansB="YES";
		if(x2<=x1-r && x1+r<=x3) {
			if(y2<=y1-r && y1+r<=y3) {
				ansR="NO";
			}
		}
		int d1=(x1-x2)*(x1-x2);
		int d2=(x1-x3)*(x1-x3);
		int d3=(y1-y2)*(y1-y2);
		int d4=(y1-y3)*(y1-y3);
		int rr=r*r;
		if(d1+d3<=rr && d1+d4<=rr && d2+d3<=rr && d2+d4<=rr) {
			ansB="NO";
		}
		System.out.println(ansR);
		System.out.println(ansB);
	}
}