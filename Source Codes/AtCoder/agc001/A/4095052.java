import java.util.*;

public class Main {
  
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String line = sc.nextLine();
    
    // N?????
    int N = Integer.parseInt(line);
    
    // L1... ?????
    line = sc.nextLine();
    String[] l1l2 = line.split(" ");
    List<Integer> kusi = new ArrayList<>();
    
    for(int i = 0; i < l1l2.length; i++ ) {
      kusi.add(Integer.parseInt(l1l2[i]));
    }
    
    Collections.sort(kusi);
    
    calc(kusi);
  }
  
  // ????
  public static void calc(List<Integer> list) {
    int total = 0;
    for(int i = 0; i < list.size(); i=i+2) {
      total += list.get(i);
    }
    
    System.out.println(total);
  }
}