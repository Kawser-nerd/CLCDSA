import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		
		ArrayList<Character> chars = new ArrayList<Character>();
		
		int one = 0;			//????????
		int two = 0;			//????????????
		
		int n = 0;
		chars.add(str.toCharArray()[0]);
		for(char x: str.toCharArray()){
			int count = 0;
			boolean flag = true;
			for(int i = 0; i < chars.size(); i++){
				if(chars.get(i) == x){
					flag = false;
				}
			}
			
			if(flag || n == 0){
				chars.add(x);
				for(char y: str.toCharArray()){
					if(x == y)	count++;
				}
			}
			
			two += count/2;
			one += count%2;
			n++;
		}
		
		int minLength = two;
		if(one != 0)	minLength = two/one;
		minLength *= 2;
		if(one > 0)	minLength += 1;
		
		System.out.println(minLength);
	}
}