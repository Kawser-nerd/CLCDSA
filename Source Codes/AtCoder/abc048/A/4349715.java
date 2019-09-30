import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
      String a=sc.nextLine();
      String po[]=a.split(" ",0);
      System.out.println(po[0].substring(0,1)+po[1].substring(0,1)+po[2].substring(0,1));
    }
}