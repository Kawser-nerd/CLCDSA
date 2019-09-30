import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int sx = sc.nextInt();
		int sy = sc.nextInt();
		int gx = sc.nextInt();
		int gy = sc.nextInt();
		int time = sc.nextInt();
		int speed = sc.nextInt();
		int girl = sc.nextInt();
		double distance = time*speed;
		for(int i = 0; i < girl; i++){
			int girlx = sc.nextInt();
			int girly = sc.nextInt();
			double ahead = Math.sqrt((sx-girlx)*(sx-girlx)+(sy-girly)*(sy-girly));
			double back = Math.sqrt((girlx-gx)*(girlx-gx)+(girly-gy)*(girly-gy));
			if((ahead+back)<=distance){
				System.out.println("YES");
				return;
			}
		}
		System.out.println("NO");
	}
}