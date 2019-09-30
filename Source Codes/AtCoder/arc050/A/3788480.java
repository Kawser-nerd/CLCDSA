import java.util.*;

public class Main {
  public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
    String C = scanner.next();
    String c = scanner.next();
    String str = c.toUpperCase();
    if(C.equals(str)){
      System.out.println("Yes");
    }else{
      System.out.println("No");
    }
  }
}