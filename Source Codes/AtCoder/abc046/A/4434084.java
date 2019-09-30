/*
?????atcoder?ABC_046?A????AtCoDeer???????
?????????????????????????
???????????????
*/
import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    int count = 1;
    if(a == b && b == c && a == c){
      System.out.println(count);
    }
    else if(a == b || b == c || a == c){
      count++;
      System.out.println(count);
    }
    else{
      count = count + 2;
      System.out.println(count);
    }
  }
}