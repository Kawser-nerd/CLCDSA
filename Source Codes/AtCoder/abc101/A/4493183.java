import java.util.*;
public class Main {
	public static void main(String[] args){
      	//???????
		Scanner sc = new Scanner(System.in);
		//int N = sc.nextInt();
    	//int M = sc.nextInt();
      	String S = sc.next();
      	//int list[] = new int[N];
      	//for(int i=0;i<N;i++){
        //	list[i] = sc.nextInt();
        //}
      	//Arrays.sort(list);
      	int cnt = 0;
		for(int i=0;i<4;i++){
        	if(S.charAt(i)=='+'){
            	cnt++;
            }else{
            	cnt--;
            }
        }
      	System.out.println(cnt);      	
    }
}