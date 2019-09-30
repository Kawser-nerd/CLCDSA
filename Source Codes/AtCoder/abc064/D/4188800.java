import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = sc.next();
		StringBuilder sb = new StringBuilder();
		sb.append(s);
		int left=0;
		int right=0;
		for(char i:s.toCharArray()){
			if(i=='('){
				left++;
			}else{
				right++;
				if(left>0){
					right--;
					left--;
				}
			}
		}
		for(int i = 0; i<left; i++){
			sb.append(")");
		}
		for(int i = 0; i<right; i++){
			sb.insert(0,"(");
		}
			System.out.println(sb);
	}
}