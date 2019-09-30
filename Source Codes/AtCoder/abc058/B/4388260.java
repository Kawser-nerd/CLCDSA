import java.util.*;

public class Main {
    public static void main(String[] args)  {
        Scanner sc=new Scanner(System.in);
      String po=sc.nextLine();
      String popo=sc.nextLine();
      for(int i=0;i<popo.length();i++){
      	System.out.print(po.substring(i,i+1)+popo.substring(i,i+1));
      }
      System.out.println((po.length()==popo.length())?"":po.substring(po.length()-1,po.length()));
    }
}