import java.util.*;
public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    int c = sc.nextInt();
    c=c*10+sc.nextInt();
    c=c*10+sc.nextInt();

    if(c%4==0){
      System.out.println("YES");
    }else{
      System.out.println("NO");
    }
  }
}