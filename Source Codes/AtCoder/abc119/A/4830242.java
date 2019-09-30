import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String[] line = s.split("/", 4);
        int[] num = new int[3];
        for(int i=0; i<3; i++){
        	num[i] = Integer.parseInt(line[i]); 
        }
		if(num[0] < 2019) System.out.println("Heisei");
        else if(num[1] < 5) System.out.println("Heisei");
        else System.out.println("TBD");
	}
}