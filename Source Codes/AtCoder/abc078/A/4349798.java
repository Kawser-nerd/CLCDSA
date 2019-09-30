import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
      String p=sc.nextLine();
      char[] po=p.toCharArray();
      
      System.out.println(((int)po[0]==(int)po[2])?"=":((int)po[0]<(int)po[2])?"<":">");
      
    }
}