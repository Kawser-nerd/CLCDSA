import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int h = scanner.nextInt();
    int m = scanner.nextInt();
    int min = h * 60 + m;
    System.out.println(18*60-min);
  }
}