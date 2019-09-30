import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int[] p = Arrays.stream(br.readLine().split(""))
      .mapToInt(Integer::parseInt).toArray();
    System.out.println(p[0]+p[1]);
  }

}