import java.io.File;
import java.io.IOException;
import java.util.*;
 
public class Main {
	public static void main(String[] args) throws IOException {
		//File file = new File("input.txt");
		//Scanner in = new Scanner(file);
		
		Scanner in = new Scanner(System.in);
		
		int N = in.nextInt();
		ArrayList<Integer> list = new ArrayList<Integer>();
		list.add(in.nextInt());
		
		for(int i = N - 1; i > 0 ; i--){
			int w = in.nextInt();
			int min = 100000;
			int index = -1;
			
			for(int j = 0; j < list.size(); j++){
				int sub = list.get(j) - w;
				if(sub >= 0 && sub < min){
					min = sub;
					index = j;
				}
			}
			
			if(index != -1) list.set(index, w);
			else list.add(w);
		}
		
		System.out.println(list.size());
	}
}