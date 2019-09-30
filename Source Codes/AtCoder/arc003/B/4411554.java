import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int N = Integer.parseInt(sc.nextLine());
    List<String> list = new ArrayList<>();
    for(int i = 0; i < N; i++){
      String s = sc.nextLine();
      StringBuffer s2 = new StringBuffer(s);
      String s3 = s2.reverse().toString();
      list.add(s3);
    }
    Collections.sort(list);
    
    for(int i = 0; i < N; i++){
      StringBuffer s2 = new StringBuffer(list.get(i));
      String s3 = s2.reverse().toString();
      System.out.println(s3);
    }
  }
}