import java.util.*;
public class Main {
	public static void main(String[] args){
      	//???????
		Scanner sc = new Scanner(System.in);
		//int N = sc.nextInt();
    	//int M = sc.nextInt();
      	//String S = sc.next();
      	int list[] = new int[3];
      	for(int i=0;i<3;i++){
        	list[i] = sc.nextInt();
        }
      	Arrays.sort(list);
      	System.out.println((list[1]-list[0])+(list[2]-list[1]));
    }
}