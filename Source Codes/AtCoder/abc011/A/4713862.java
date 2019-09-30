import java.util.Scanner;

public class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    
    int i  = sc.nextInt();
    if (i == 11 ){
      System.out.println(12);
    } else {
      System.out.println((i + 1) % 12);
    }
  }
}