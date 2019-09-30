import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);

		int w = scan.nextInt();
		int h = scan.nextInt();
		int n = scan.nextInt();

		int x_min = 0;
		int y_min = 0;
		int x_max = w;
		int y_max = h;

		for(int i = 0; i < n; i++){
			int x = scan.nextInt();
			int y = scan.nextInt();
			int a = scan.nextInt();

			if(a == 1){
				if(x_min < x){
					x_min = x;
				}
			}
			else if(a == 2){
				if(x_max > x){
					x_max = x;
				}
			}
			else if(a == 3){
				if(y_min < y){
					y_min = y;
				}
			}
			else if(a == 4){
				if(y_max > y){
					y_max = y;
				}
			}
		}

		int area = 0;
		if(x_max > x_min && y_max > y_min){
			area = (x_max - x_min) * (y_max - y_min);
		}
		System.out.println(area);
	}
}