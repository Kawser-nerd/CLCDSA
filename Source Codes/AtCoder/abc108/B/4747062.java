import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x1 = sc.nextInt(), y1 = sc.nextInt(), x2 = sc.nextInt(), y2 = sc.nextInt();
		int xdis = 0, ydis = 0;
		if(x1 >= x2) {
			xdis = x1 - x2;
			if(y1 >= y2) {
				ydis = y1 - y2;
				System.out.printf("%d %d %d %d\n",x2+ydis,y2-xdis,x1+ydis,y1-xdis);
			}else if(y1 < y2) {
				ydis = y2 - y1;
				System.out.printf("%d %d %d %d\n",x2-ydis,y2-xdis,x1-ydis,y1-xdis);
			}
		}else if(x1 < x2) {
			xdis = x2 - x1;
			if(y1 >= y2) {
				ydis = y1 - y2;
				System.out.printf("%d %d %d %d\n",x2+ydis,y2+xdis,x1+ydis,y1+xdis);
			}else if(y1 < y2) {
				ydis = y2 - y1;
				System.out.printf("%d %d %d %d\n",x2-ydis,y2+xdis,x1-ydis,y1+xdis);
			}
		}
		sc.close();
	}
}