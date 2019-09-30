import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.stream.Collectors;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] s = Arrays.stream(br.readLine().split(""))
      .sorted().collect(Collectors.toList()).toArray(new String[5]);
    int n = Integer.parseInt(br.readLine());
    br.close();
    int i = (n-1) / 5;
    int j = n - 1 - 5*i;
    System.out.println(s[i]+s[j]);
  }

}