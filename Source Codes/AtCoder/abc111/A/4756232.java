import java.util.*;

public class Main {
  public static void main(String[] args) {
	Scanner scanner = new Scanner(System.in);
    String text = scanner.nextLine();
    
    StringBuilder result = new StringBuilder();
    for (int ix = 0; ix < text.length(); ix++) {
      if (text.charAt(ix) == '9') {
        result.append(1);
      } else {
        result.append(9);
      }
    }
    
    System.out.println(result);
  }
}