import java.util.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int h = s.nextInt();
    int w = s.nextInt();
    System.out.println((h-1)*w + h*(w-1));
  }
}