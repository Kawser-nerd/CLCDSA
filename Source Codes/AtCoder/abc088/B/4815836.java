import java.util.Arrays;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = Integer.parseInt(in.nextLine());
    String[] tmp = in.nextLine().split(" ");
    int[] a = Arrays.stream(tmp).mapToInt(Integer::parseInt).toArray();
    Arrays.sort(a);
    int aliceSum = 0;
    int bobSum = 0;
    boolean isAliceTurn = true;
    for (int i = n - 1; i >= 0; i--) {
      if (isAliceTurn) {
        aliceSum += a[i];
      } else {
        bobSum += a[i];
      }
      isAliceTurn = !isAliceTurn;
    }
    System.out.println(aliceSum - bobSum);
  }

}