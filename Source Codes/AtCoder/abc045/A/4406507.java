import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int h = sc.nextInt();
    int line = a + b;
    int area = line*h/2;
    System.out.println(area);
  }
}