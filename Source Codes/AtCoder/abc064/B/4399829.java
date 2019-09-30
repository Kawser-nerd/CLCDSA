import java.util.*;
public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int max = sc.nextInt();
    int min = max;
	
    for(int i = 0;i < n-1;i++){
      int s = sc.nextInt();
      if(s > max){
        max = s;
      }else if(min > s){
        min = s;
      }
    }
    System.out.println(max-min);
  }
}