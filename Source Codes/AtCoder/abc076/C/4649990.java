import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;


public class Main {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		char[] S = sc.next().toCharArray();
		char[] T = sc.next().toCharArray();
		int pos = S.length - 1 ;
		
		while(pos>=0){
			int offset = pos;
			boolean flag = true;
			for(int i=T.length-1 ; i>=0; i--){
				char c = T[i];
				if (offset < 0){
					flag = false;
					pos = -1;
					break;
				}
				if(S[offset]=='?' || S[offset]==c){
					offset--;
				}else{
					pos--;
					flag = false;
					break;
				}
			}
			if(flag){
				pos = pos-T.length+1;
				for(char c : T){
					S[pos] = c;
					pos++;
				}
				for(char c : S){
					if(c == '?'){
						System.out.print("a");
					}else{
						System.out.print(c);
					}
				}
				return;
			}
				
		}
		
		System.out.println("UNRESTORABLE");
		
		sc.close();
	}
}