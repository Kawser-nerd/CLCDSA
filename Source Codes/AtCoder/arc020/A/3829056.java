import java.util.Scanner;
import java.util.Arrays;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int a = scanner.nextInt();
    int b = scanner.nextInt();
    if(Math.abs(a) < Math.abs(b)){
      System.out.println("Ant");
    }else if(Math.abs(a) > Math.abs(b)){
      System.out.println("Bug");
    }else{
      System.out.println("Draw");
    }
  }
}