import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int[] a = {0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
    System.out.println(a[sc.nextInt()] == a[sc.nextInt()] ? "Yes":"No");
  }
}