import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
      String a=sc.nextLine();
      String []b=a.split(" ",0);
      System.out.println((b[0].substring(b[0].length()-1,b[0].length()).equals(b[1].substring(0,1))&&b[1].substring(b[1].length()-1,b[1].length()).equals(b[2].substring(0,1)))?"YES":"NO");
    }
}