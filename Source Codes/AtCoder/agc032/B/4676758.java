import java.util.*;
class Main{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int num = sc.nextInt();
    System.out.println(num * (num - 1) / 2 - num / 2);
    for(int i = 1; i <= num; i ++) {
      for(int j = 1; j < i; j ++) {
        if(i + j == num / 2 * 2 + 1) { continue; }
        System.out.println(i+" "+j);
      }
    }
  }
}