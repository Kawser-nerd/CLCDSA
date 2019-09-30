import java.util.Scanner;

public class Main{
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		String s=in.next();
		boolean t=false;
		for(int i=0;i<s.length()-2;i++){
			if(s.charAt(i)==s.charAt(i+1)){
				System.out.print((i+1)+" "+(i+2));
				t=true;
				break;}
			if(s.charAt(i)==s.charAt(i+2)){
				System.out.print((i+1)+" "+(i+3));
				t=true;
				break;
			}}
		if (!t){
			if(s.charAt(s.length()-2)==s.charAt(s.length()-1)){
				System.out.print((s.length()-1)+" "+s.length());
			}else{
			System.out.print("-1 -1");}
		}
		
	}
}