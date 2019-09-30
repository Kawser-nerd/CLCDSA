import java.util.*;
	public class Main{public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
  		String a[]=sc.nextLine().split("",0);
      String at[]=new String[]{"a","t","c","o","d","e","r"};
      String b[]=sc.nextLine().split("",0);
        boolean po=true;
      for(int i=0;i<a.length;i++){
      	  if(!a[i].equals(b[i])){
          	  if(a[i].equals("@")){
                  boolean popo=false;
                  for(int j=0;j<at.length;j++){
                      if(b[i].equals(at[j])){
                          popo=true;
                      }
                  }
                if(!popo){
                    po=false;break;
                }
              }
              else if(b[i].equals("@")){
                boolean popo=false;
                  for(int j=0;j<at.length;j++){
                      if(a[i].equals(at[j])){
                          popo=true;
                      }
                  }
                if(!popo){
                    po=false;break;
                }
              }
              else {
                  po=false;
                  break;
              }
          }
      }System.out.println((po)?"You can win":"You will lose");
  	}
}