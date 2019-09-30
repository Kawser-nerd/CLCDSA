import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
      String a[]=sc.nextLine().split("",0);
      System.out.println((a[0].equals(a[1])&&a[2].equals(a[1])||a[1].equals(a[2])&&a[3].equals(a[2]))?"Yes":"No");
    }
}