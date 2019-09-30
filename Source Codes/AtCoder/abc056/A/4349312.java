import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
      String a=sc.nextLine();
      String []b=a.split(" ",0);
      System.out.println((b[0].equals(b[1]))?"H":"D");
    }
}