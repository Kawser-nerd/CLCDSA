import java.util.*;
public class Main{
	public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	int counter1 = 0,counter0 = 0;
	String N = sc.next();
	String S[] = new String[N.length()];
		for(int i=0; i<N.length(); i++){
		S[i] = String.valueOf(N.charAt(i));
			if(S[i].equals("1")){
			counter1++;
			}
          	else{
			counter0++;
			}
		}
		System.out.println(Math.min(counter0*2,counter1*2));
		
	}
}