import java.util.*;
import java.io.*;

public class Main{
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] s = br.readLine().split(" ");
    int area = Integer.parseInt(s[0]) * Integer.parseInt(s[1]) / 2;
    System.out.println(area);
  }
}