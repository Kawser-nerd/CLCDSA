import java.util.*;

public class Main {
  public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
    int H = scanner.nextInt();
    int W = scanner.nextInt();
    System.out.println((H-1)*W+(W-1)*H);
  }
}