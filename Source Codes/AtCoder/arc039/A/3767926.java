import java.util.*;

class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int a=sc.nextInt();
    int b=sc.nextInt();
    int res=Math.max(Math.max(Math.max((a%100+900)-b,a-(b%100+100)),Math.max((a/100*100+a%10+90-b),(a-(b/100*100+b%10)))),Math.max(a/10*10+9-b,(a-(b/10*10))));
    System.out.println(res);
  }
}