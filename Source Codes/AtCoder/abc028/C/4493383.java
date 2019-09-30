import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int[] n = new int[5];
    for(int i = 0; i < 5; i++){
      n[i] = sc.nextInt();
    }
    int a = n[4] + n[3] + n[0];
    int b = n[4] + n[2] + n[1];
    
    System.out.println(a > b ? a : b);
  }
}