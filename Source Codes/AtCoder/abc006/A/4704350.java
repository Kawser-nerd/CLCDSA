import java.util.Scanner;

public class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int mod = n % 3;
    if ( mod == 0) {
    	System.out.println("YES");
    } else {
      System.out.println("NO");
    }
  }
}