import java.util.*;
public class Main {
	public static void main(String[] args){
      	//???????
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
      	if(N<105){
        	System.out.println(0);
        }else{
        	int cntnum = 0;
          	for(int i=105;i<=N;i+=2){
              	int cnt = 0;
            	for(int j=1;j<=N;j++){
                	if(i%j==0){
                    	cnt++;
                    }
                }
              	if(cnt==8){
                	cntnum++;
                }
            }
          	System.out.println(cntnum);
        }
    }
}