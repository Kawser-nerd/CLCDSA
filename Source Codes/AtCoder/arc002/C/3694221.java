import java.util.*;
public class Main{
	public static void main(String... argv){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String command = sc.next();
		String[] keywords = {"AA", "AB", "AX", "AY",
                         "BA", "BB", "BX", "BY",
                         "XA", "XB", "XX", "XY",
                         "YA", "YB", "YX", "YY"
                        };
		int ans = command.length();
		for(int i=0;i<keywords.length-1;i++){
			for(int j=i;j<keywords.length;j++){
				int count = 0;
				int tempAns = n;
				while(count < n-1){
					String subStr = command.substring(count, count+2);
					if(subStr.equals(keywords[i]) || subStr.equals(keywords[j])){
						tempAns--;
						count+=2;
					}
					else{count++;}
				}
				ans = Math.min(ans, tempAns);
			}
		}
		System.out.println(ans);
	}
}