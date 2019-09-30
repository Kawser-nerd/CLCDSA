import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String S = sc.next();

		List<String> sList = Arrays.asList(S.split(""));

		int zeroCount = 0;
		int oneCount= 0;
		int ans = 0;
		for(String s : sList){
			if(s.equals("0")){
				zeroCount++;
			}else{
				oneCount++;
			}
		}

		if(zeroCount>oneCount){
			ans = oneCount*2;
		}else{
			ans = zeroCount*2;
		}

		System.out.println(ans);

	}
}