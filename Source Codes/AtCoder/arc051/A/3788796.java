import java.util.*;

public class Main {
  public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
    int x1 = scanner.nextInt();
    int y1 = scanner.nextInt();
    int r = scanner.nextInt();
    int x2 = scanner.nextInt();
    int y2 = scanner.nextInt();
    int x3 = scanner.nextInt();
    int y3 = scanner.nextInt();
    //?????????????????
    //?????????????????
    //???
    if(x1+r <= x3 && x1-r >= x2 && y1+r <= y3 && y1-r >= y2){
      System.out.println("NO");
      System.out.println("YES");
    }else if((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) <= r*r && (x2-x1)*(x2-x1)+(y3-y1)*(y3-y1) <= r*r &&
    (x3-x1)*(x3-x1)+(y2-y1)*(y2-y1) <= r*r && (x3-x1)*(x3-x1)+(y3-y1)*(y3-y1) <= r*r){
      System.out.println("YES");
      System.out.println("NO");
    }else{
      System.out.println("YES");
      System.out.println("YES");
    }

  }
}