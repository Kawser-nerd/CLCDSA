import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

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
		String[] abc = br.readLine().split(" ");
		int a = Integer.parseInt(abc[0]);
		int b = Integer.parseInt(abc[1]);
		boolean flag = false;
		for(int c = 1;c<=3;c++){
			if ((a*b*c)%2 == 1){
				flag = true;
			}
		}

		if(flag){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}
	}

}