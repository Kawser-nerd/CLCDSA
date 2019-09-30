import java.util.*;

public class Main{

  public static void main(String args[]){

    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String str = sc.next();
    int[] c = new int[5];

    for(int i=0; i<n; i++){
      int tmp = Integer.parseInt(str.substring(i,i+1));
      if(tmp == 1){
        c[1]++;
      }else if(tmp == 2){
        c[2]++;
      }else if(tmp == 3){
        c[3]++;
      }else if(tmp == 4){
        c[4]++;
      }
    }

    int max = c[1];
    int min = c[1];
    for(int i=2; i<5; i++){
        max = Math.max(max,c[i]);
        min = Math.min(min,c[i]);
    }

    pl(max + " " +min);
  }

  private static void pr(Object o){
    System.out.print(o);
  }
  private static void pl(Object o){
    System.out.println(o);
  }

}