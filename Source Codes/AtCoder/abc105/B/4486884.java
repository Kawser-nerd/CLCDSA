import java.util.*;
public class Main {
	public static void main(String[] args){
      	//???????
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
      	boolean flg = true;
      	if(N<4){
        	System.out.println("No");
        }else{
      		for(int i=0;i<30;i++){
              	if(!flg){
                 	break;
                 }
        		for(int j=0;j<30;j++){
            		if(N==7*i+4*j){
                		System.out.println("Yes");
                	  	flg = false;
                  		break;
               		 }
           	 	}
        	}
        	if(flg){
        		System.out.println("No");
        	}
        }
    }
}