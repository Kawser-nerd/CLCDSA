import java.util.*;
public class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    String[] arr = new String[6];
    arr[0] = "1";
    arr[1] = "2";
    arr[2] = "3";
    arr[3] = "4";
    arr[4] = "5";
    arr[5] = "6";
    String r = "";
    int c = N % 30;
    for(int i = 0; i < c; i++){
      r = arr[( i % 5 )];
      arr[( i % 5 )] = arr[( i % 5 ) + 1];
      arr[( i % 5 ) + 1] = r;
    }

    System.out.println(arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5]);
  }
}