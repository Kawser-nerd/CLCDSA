import java.util.*;
public class Main {
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int []z = new int[3];
	int A = sc.nextInt();
	int B = sc.nextInt();
	z[0]=A+B;z[1]=A-B;z[2]=A*B;
	int max = z[0];
	for(int i=1;i<3;i++) {
    if(max<z[i]){
    	max = z[i];
    }		
	}
	System.out.println(max);	
	}
}