import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String day = sc.next();
    int ans = 0;
    if(day.equals("Monday")) ans = 5;
    if(day.equals("Tuesday")) ans = 4;
    if(day.equals("Wednesday")) ans = 3;
    if(day.equals("Thursday")) ans = 2;
    if(day.equals("Friday")) ans = 1;
    System.out.println(ans);
  }
}