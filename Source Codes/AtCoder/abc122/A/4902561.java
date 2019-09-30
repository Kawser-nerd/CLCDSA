import java.util.*;

public class Main {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    
    String s = sc.next();
    String a = null;
    
    switch(s) {
        case "A":
            a = "T";
            break;
        case "T":
            a = "A";
            break;
        case "G":
            a = "C";
            break;
        case "C":
            a = "G";
            break;
    }
    
    System.out.println(a);
  }
}