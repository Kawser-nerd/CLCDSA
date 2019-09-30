import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) {

    int n = 0;
    int[] nums = null;
    try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
      n = Integer.parseInt(br.readLine());
      nums = new int[n];

      for (int i = 0; i < nums.length; i++) {
        nums[i] = Integer.parseInt(br.readLine());
      }
    } catch (IOException e) {
      e.printStackTrace();
      System.exit(1);
    }

    boolean b = false;
    int idx = 0;
    int sum = 0;
    for (int i = 0; i <= nums.length - 1; i++) {
      sum++;
      if (nums[idx] == 2) {
        b = true;
        break;
      }
      else {
        idx = nums[idx]-1;
      }
    }

    System.out.print(b == true ? sum : -1);
  }
}