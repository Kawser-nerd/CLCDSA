import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    List<Integer> list = new ArrayList<>();
    int i = 1;
    while(true){
      int r = (a * i) % b;
      if(r == c){
        System.out.println("YES");
        System.exit(0);
      }
      if(list.contains(r)){
        System.out.println("NO");
        System.exit(0);
      }
      list.add(r);
      i++;
    }
  }
}