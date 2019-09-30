import java.util.*;

public class Main {
    public static void main(String[] args)  {
        Scanner sc=new Scanner(System.in);
      Map<Integer,String>map=new HashMap<Integer,String>();
      int po=0;int n=sc.nextInt();sc.nextLine();
      int sum=0;
      for(int i=0;i<n;i++){
          String s=sc.nextLine();
          String ss[]=s.split(" ",0);
          int m=Integer.parseInt(ss[1]);
          po=Math.max(m,po);
          sum+=m;
          map.put(m,ss[0]);
      }
      System.out.println((2*po>sum)?map.get(po):"atcoder");
    }
}