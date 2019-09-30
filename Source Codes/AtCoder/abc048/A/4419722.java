import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String A = sc.next();
    String S = sc.next();
    String C = sc.next();
    String[] A_array = A.split("");
    String[] S_array = S.split("");
    String[] C_array = C.split("");
    System.out.println(A_array[0]+S_array[0]+C_array[0]);
  }
}