import java.util.Scanner;

public class Main
{
  
  public static void main(String[] args)
  {
    Scanner scan = new Scanner(System.in);
    
    int a = scan.nextInt();
    int b = scan.nextInt();
    
    int multiplyNum = a * b;
    
    String result = (multiplyNum % 2 == 0) ? "Even" : "Odd";
    System.out.println(result);
  }
}