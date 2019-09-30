import java.util.*;
	public class Main{public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
  		String a[]=sc.nextLine().split("",0);
        String po=a[0];int count=1;
      String ans="";
        for(int i=1;i<a.length;i++){
            if(po.equals(a[i]))count++;
            else{
                ans+=po+count;
                po=a[i];
            	count=1;
            }
        }
      ans+=po+count;
      System.out.println(ans);
  	}
}