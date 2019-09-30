import java.util.*;
public class Main {

	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int []hairetu=new int[3];
        hairetu[0] = sc.nextInt();
        hairetu[1] = sc.nextInt();
        hairetu[2] = sc.nextInt();
        int K = sc.nextInt(); 
        int max = hairetu[0];
        int a=0;
        for(int j=0;j<K;j++) {
        for(int i=0;i<3;i++){
        	if(max<hairetu[i]){
        		max=hairetu[i];
        		 a =i;
        	}
        }
        hairetu[a]=max*2;
        
        }
        int sum =0;
        for(int i=0;i<3;i++){
        	sum+=hairetu[i];
        }
        System.out.println(sum);
	}
}