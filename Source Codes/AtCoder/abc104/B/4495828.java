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
      	boolean o1 = S.charAt(0) == 'A';
      	boolean o3 = true;
      	for(int i=1;i<S.length();i++){
        	if(S.charAt(i)!='C' && Character.isUpperCase(S.charAt(i))){
            	o3 = false;
              	break;
            }
        }
      	int cnt = 0;
      	boolean o2 = true;
      	if(S.charAt(0)=='C' ||S.charAt(1)=='C'||S.charAt(S.length()-1)=='C'){
        	o2 = false;
        }else{
      	for(int i=0;i<S.length();i++){
        	if(S.charAt(i) == 'C'){
            	cnt++;
            }
        }
        if(cnt!=1){
                  	o2 = false;
                	
                }
        }
      	if(o1 && o2 && o3){
        	System.out.println("AC");
        }else{
        	System.out.println("WA");
        }
    }
}