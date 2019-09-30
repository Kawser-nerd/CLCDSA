import java.util.Scanner;

class Main{
	static int x1;
	static int y1;
	static int r;
	static int x2;
	static int y2;
	static int x3;
	static int y3;
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		x1=sc.nextInt();
		y1=sc.nextInt();
		r=sc.nextInt();
		x2=sc.nextInt();
		y2=sc.nextInt();
		x3=sc.nextInt();
		y3=sc.nextInt();
		if(isareaRC()) {
			System.out.println("NO");
		}
		else {
			System.out.println("YES");
		}

		if(isareaCR()) {
			System.out.println("NO");
		}
		else {
			System.out.println("YES");
		}
	}
	static boolean isareaRC() { //RECT > CIRCLE ????????
		if(x1-r>=x2 && x1+r<=x3 && y1+r<=y3 && y1-r>=y2) {
			return true;
		}
		return false;
	}

	static boolean isareaCR() { //CIRCLE > RECT ????????
		if((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)<=r*r) {
			if((x3-x1)*(x3-x1)+(y2-y1)*(y2-y1)<=r*r) {
				if((x2-x1)*(x2-x1)+(y3-y1)*(y3-y1)<=r*r) {
					if((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)<=r*r) {
						return true;
					}
				}
			}
		}
		return false;
	}
}