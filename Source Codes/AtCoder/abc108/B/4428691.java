import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
    	Scanner input = new Scanner(System.in);
      	int x_1 = input.nextInt();
      	int y_1 = input.nextInt();
      	int x_2 = input.nextInt();
      	int y_2 = input.nextInt();
      	int height = y_2 - y_1;
      	int width = x_2 - x_1;
      
      	System.out.print((x_2 - height) + " " + (y_2 + width) + " " + (x_1 - height) + " " + (y_1 + width));
    }
}