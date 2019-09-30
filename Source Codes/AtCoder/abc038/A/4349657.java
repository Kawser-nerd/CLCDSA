import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
      String a=sc.nextLine();
      System.out.println((a.substring(a.length()-1,a.length()).equals("T"))?"YES":"NO");
    }
}