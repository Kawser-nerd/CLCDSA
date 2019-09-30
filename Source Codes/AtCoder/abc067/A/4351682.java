import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
      int a=sc.nextInt();int b=sc.nextInt();
      System.out.println(((a+b)%3==0||a%3==0||b%3==0)?"Possible":"Impossible");
    }
}