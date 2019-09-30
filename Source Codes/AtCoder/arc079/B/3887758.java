import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		long x=sc.nextLong();
		
		int rem=(int)(x%50);
		long sho=x/50;
		
		System.out.println(50);
		for(int i=0;i<50;i++){
			if(i<rem){
				System.out.print((sho+50)+" ");
			}else{
				System.out.print((sho+49-rem)+((i==49)?"\n":" "));
			}
		}
	}
}