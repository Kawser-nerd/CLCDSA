import java.util.Scanner;
import java.util.Arrays;

public class Main{
  public static void main(String[] args){
    Scanner scanner = new Scanner(System.in);
    String s = scanner.next() + " ";
    String t = "";
    int count = 0;
    for(int i = 1; i < s.length(); i++){
      count++;
      if(s.charAt(i)!=s.charAt(i-1)){
        t += String.valueOf(s.charAt(i-1));
        t += String.valueOf(count);
        count = 0;
      }
    }
    System.out.println(t);
  }
}