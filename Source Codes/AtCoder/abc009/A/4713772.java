import java.util.Scanner;

public class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    int i = sc.nextInt();
    int mod = 0;
    if ( i == 1 ) {
      System.out.println("1");
    } else {
      mod = i % 2;
      i = i /2;
      System.out.println(mod + i);
    }
  }
}