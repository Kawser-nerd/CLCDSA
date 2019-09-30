import java.util.*;
public class Main {
  public static void main(String[] args){

    Scanner sc = new Scanner(System.in);
    int a = Integer.parseInt(sc.nextLine());
    Integer arr[] = new Integer[a];

    for (int i=0; i<a; i++) {
      arr[i] = sc.nextInt();
    }
    Arrays.sort(arr);

    System.out.println(arr[0]);
  }
}