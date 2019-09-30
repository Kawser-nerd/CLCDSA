import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int h = sc.nextInt();
    int w = sc.nextInt();
    StringBuilder sb = new StringBuilder();
    for(int i = 0; i < w+2; i++){
      sb.append("#");
    }
    sb.append("\n");
    String tmp = sb.toString();
    for(int i = 0; i < h; i++){
      sb.append("#");
      sb.append(sc.next());
      sb.append("#\n");
    }
    sb.append(tmp);
    System.out.print(sb.toString());
  }
}