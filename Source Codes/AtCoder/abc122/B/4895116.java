import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

		String S = sc.next();

		String SList[] = new String[S.length()];
		for(int i=0; i<S.length(); i++){
			SList[i] = S.substring(i,i+1);
		}

		int maxlength = 0;
		int length = 0;

		for(int s=0; s<SList.length; s++){
			if(SList[s].matches("(A|C|G|T)*")){
				length++;
				if(maxlength < length){
					maxlength = length;
				}
			}else{
				length = 0;
				continue;
			}
		}
		System.out.println(maxlength);
    }
}