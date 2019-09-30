import java.util.*;
import java.io.*;

public class Main{
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] s = br.readLine().split(" ");
    double ans = Double.parseDouble(s[0]) / Double.parseDouble(s[1]);
    System.out.println(ans);
  }
}