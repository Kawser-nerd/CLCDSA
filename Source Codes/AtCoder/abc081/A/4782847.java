import java.util.*;
public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    String a = sc.next();
    String[] arr = a.split("");
    int s = 0;
    if(arr[0].equals("1")){ ++s; }
    if(arr[1].equals("1")){ ++s; }
    if(arr[2].equals("1")){ ++s; }
    System.out.println(s);
  }
}