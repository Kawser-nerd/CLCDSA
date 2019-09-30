import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int tmp = sc.nextInt() +  sc.nextInt();
    System.out.println(tmp < 10 ? tmp : "error");
  }
}