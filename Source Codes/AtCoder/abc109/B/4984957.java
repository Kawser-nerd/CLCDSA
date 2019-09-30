import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

//Atcoder?


/*
 * BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] abc = br.readLine().split(" ");
		int a = Integer.parseInt(abc[0]);
		int b = Integer.parseInt(abc[1]);
		int c = Integer.parseInt(abc[2]);
 */
public class Main {
	public static void main(String[] args)throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		List<String> sir = new ArrayList<String>();
		boolean isCorrect = true;
		String lastWord="";
		for(int n=0;n<N;n++){
			String word = br.readLine();
			String[] chr = word.split("");

			if(n==0)lastWord = chr[chr.length-1];
			else{
				if(!lastWord.equals(chr[0])){
					isCorrect = false;
					//System.out.println("lastword");
					break;
				}else{
					if(sir.contains(word)){
						isCorrect = false;
						//System.out.println("sameword");
						break;
					}
					sir.add(word);
					lastWord = chr[chr.length-1];
				}
			}

			sir.add(word);
		}
		if(isCorrect)System.out.println("Yes");
		else System.out.println("No");


	}

}