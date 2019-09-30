import java.util.*;
public class Main {
  public static void main(String[] args) {
     Scanner sc = new Scanner(System.in);
     String name = sc.next();
     String ck1 = ""; 
     String ck2 = "";
     String [] kainame = name.split("");
     for (int i = 0 ; i < name.length() ; i++) {
         ck1 = kainame[i];
         ck2 = kainame[name.length() - 1 - i];
         //System.out.println("ck1 " + ck1);
         //System.out.println("ck2 " + ck2);
         if (!(ck1.equals(ck2))) {
           System.out.println("NO");
           System.exit(0);
         } 
     }
     System.out.println("YES"); 
  }
}