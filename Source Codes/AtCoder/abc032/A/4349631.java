import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
      int a=sc.nextInt();
      int b=sc.nextInt();
      int c=sc.nextInt();
      while(true){
      if(c%b==0&&c%a==0)break;
        c++;
      }System.out.println(c);
    }
}