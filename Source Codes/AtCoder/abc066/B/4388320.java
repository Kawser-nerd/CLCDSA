import java.util.*;

public class Main {
    public static void main(String[] args)  {
        Scanner sc=new Scanner(System.in);
      String po=sc.nextLine();
      if(po.length()%2==1)po=po.substring(0,po.length()-1);
      else po=po.substring(0,po.length()-2);
      while(po.length()!=0){
          if(po.substring(0,po.length()/2).equals(po.substring(po.length()/2,po.length())))break;
          else if (po.length()==2)po="";
          else po=po.substring(0,po.length()-2);
      }
      System.out.println(po.length());
    }
}