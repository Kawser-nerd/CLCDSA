import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Map<String,Integer>po=new HashMap<String,Integer>();
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        boolean ppp=true;
        sc.nextLine();
        String g=sc.nextLine();
        po.put(g,0);
      String nstr=g.substring(g.length()-1,g.length());
        for(int i=0;i<n-1;i++){
        	String str=sc.nextLine();
            if(po.containsKey(str)){
                ppp=false;
                break;
            }
            else {
                if(nstr.equals(str.substring(0,1))){
                    nstr=str.substring(str.length()-1,str.length());
                    po.put(str,0);
                }
                else{
                    ppp=false; break;
                }
                
            }
        }
      System.out.println((ppp)?"Yes":"No");
    }
}