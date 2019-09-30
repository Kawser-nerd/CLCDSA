import java.util.*;

public class Main{
  public static void main(String[] args){
    /*
    int a = 101;
    */
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = 0;
    int[] s;
    s = new int[3];
    s[0] = a / 100;
    s[1] = (a % 100) / 10;
    s[2] = a % 10;
    for(int i = 0; i < 3; i++){
      if(s[i] == 1){
        b++;
      }
    }
    System.out.println(b);
  }
}