import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
      int n=sc.nextInt();
      String po=sc.nextLine();po=sc.nextLine();
      int count=0;
      for(int i=1;i<po.length();i++){
        int nm=0;
      	String a=po.substring(0,i);
        String b=po.substring(i);
        Map<String,Integer>m=new HashMap<String,Integer>();
        for(int j=0;j<a.length();j++){
        	m.put(a.substring(j,j+1),1);
        }
        for(int j=0;j<b.length();j++){
        	if(m.get(b.substring(j,j+1))!=null){
            	nm++;
              m.put(b.substring(j,j+1),null);
            }
        }
        //System.out.println(a+" "+b+" "+nm);
        count=Math.max(count,nm);
      }
      System.out.println(count);
    }
}