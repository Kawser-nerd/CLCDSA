import java.util.*;

public class Main{
	private static Scanner sc=new Scanner(System.in);
	
	public static void main(String[] args){
		int na=readInt();
		int nb=readInt();
		HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
		for(int i=0;i<na;i++){
			int a=readInt();
			Integer x=map.get(a);
			if(x==null)map.put(a,1);
			else map.put(a,x+1);
		}
		for(int i=0;i<nb;i++){
			int a=readInt();
			Integer x=map.get(a);
			if(x==null)map.put(a,1);
			else map.put(a,x+1);
		}
		int b=0,c=0;
		for(Integer t:map.keySet()){
			Integer x=map.get(t);
			if(x==2)b++;
			if(x>0)c++;
		}
		double ans=1.0*b/c;
		System.out.printf("%.10f\n",ans);
	}
	
	private static int readInt(){
		return Integer.parseInt(sc.next());
	}
}