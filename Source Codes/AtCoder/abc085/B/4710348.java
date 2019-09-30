import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
     int N = sc.nextInt();
     int []hairetu = new int[N];
     int ans =1;
     for(int i=0;i<N;i++){
    	 hairetu[i]=sc.nextInt();
     }
     for(int i=0;i<N-1;i++){
    	 for(int j=0;j<N-1-i;j++){
    		 if(hairetu[j]<hairetu[j+1]){
    			 int temp = hairetu[j];
    			 hairetu[j]=hairetu[j+1];
    			 hairetu[j+1]=temp;
    		 }
    	 }
     }
     int now = hairetu[0];
     for(int i=0;i<N;i++){
    	 if(now>hairetu[i]){
    		 now=hairetu[i];
    		 ans++;
    	 }
     }
     System.out.println(ans);
     
     
	}
}