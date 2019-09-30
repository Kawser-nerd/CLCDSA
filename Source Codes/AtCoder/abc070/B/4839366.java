import java.util.*;
public class Main {

	public static void main(String[] args) {
	 Scanner sc = new Scanner(System.in);
      int A = sc.nextInt();
      int B = sc.nextInt();
      int C = sc.nextInt();
      int D = sc.nextInt();
      int count=0;
      int []hairetu = new int [B-A];
      int []hairetu2 = new int [D-C];
      for(int i=A+1;i<=B;i++) {
    	  hairetu[i-A-1]=i;
      }
      for(int i=C+1;i<=D;i++) {
    	  hairetu2[i-C-1]=i;
      }
      for(int i=0;i<B-A;i++) {
    	  for(int j=0;j<D-C;j++) {
    		  if(hairetu[i]==hairetu2[j]) {
    			  count++;
    		  }
    	  }
      }
      System.out.println(count);
	}
	}