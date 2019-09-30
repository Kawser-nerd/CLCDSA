//

import java.util.Scanner;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		int w = sc.nextInt();
		int a = sc.nextInt();
		int b = sc.nextInt();
		
		Line line1 = new Line(a,a+w);
		Line line2 = new Line(b,b+w);
		
		System.out.println(Math.abs(line1.getL()-line2.getL())<=w?0:Math.abs(line2.getL()-line1.getL())-w);
	}
}

class Line{
	private int L;
	private int R;

	Line(int a, int b) {L=a; R=b;}

	int getL() {return L;}
	int getR() {return R;}
	int getLength() {return R-L;}
	void setL(int n) {L = n;}
	void setR(int n) {R = n;}
}