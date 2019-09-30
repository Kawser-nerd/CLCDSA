import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
      Map<String,Integer>map=new HashMap<String,Integer>();
      String po=sc.nextLine();
      int n=sc.nextInt();
      for(int i=0;i<po.length()-n+1;i++){
          map.put(po.substring(i,i+n),0);
      }
      System.out.println(map.size());
    }
}