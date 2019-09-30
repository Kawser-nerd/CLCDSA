import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int min = 1000;
    int max = 0;
    for(int i = 0; i < n; i++){
      int tmp = sc.nextInt();
      min = tmp > min ? min : tmp;
      max = max > tmp ? max : tmp;
    }
    System.out.println(max - min);
  }
}