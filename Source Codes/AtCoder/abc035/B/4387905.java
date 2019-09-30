import java.util.*;

public class Main {
    public static void main(String[] args)  {
        Scanner sc=new Scanner(System.in);
      String po=sc.nextLine();
      int n=sc.nextInt();
      int count=0;
      int x=0,y=0;
      String s[]=po.split("",0);
      for(int i=0;i<s.length;i++){
      	if(s[i].equals("U"))y--;
        else if(s[i].equals("D"))y++;
        else if(s[i].equals("R"))x++;
        else if(s[i].equals("L"))x--;
        else count++;
      }
      int h=Math.abs(x)+Math.abs(y);
      System.out.println((n==1)?h+count:(h<count)?((h-count)%2==0)?0:1:h-count);
    }
}