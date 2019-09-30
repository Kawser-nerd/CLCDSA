import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
  static int mod = 1000000007;

  public static void main(String[] args) throws FileNotFoundException {

//    Scanner cin = new Scanner(new FileReader("input.txt"));
    Scanner cin = new Scanner(System.in);

    int n = cin.nextInt();
    String s = cin.next();
    int[] dict = new int[26];

    for (int i = 0; i < n; i++) {
      dict[s.charAt(i) - 'a']++;
    }
//    System.out.println(Arrays.toString(dict));
    long res = dict[0]+1;
    for (int i = 1; i < 26; i++) {
      res = res * (dict[i] + 1) % mod;
    }
    System.out.println(res-1);

  }
}