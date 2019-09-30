import java.util.*;
public class Main{
  public static void main(String[]args){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    ArrayList<Integer>po=new ArrayList<Integer>();
    for(int i=0;i<n;i++){
      po.add(sc.nextInt());
    }
    for(int i=0;i<po.size()-1;i++){
    	for(int j=i;j<po.size()-1;j++){
        	if(po.get(i).equals(po.get(j+1))){
        	    po.remove(j+1);
        	    j--;
        	}
        }
    }
    Collections.sort(po);
    System.out.println(po.get(po.size()-2));
  }
}