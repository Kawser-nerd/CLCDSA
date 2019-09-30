import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class Main {
	
	enum Status{
		X, 
		O,
		Draw,
		Incomplete,
	}
	
	public static void main(String[] args) throws IOException{
		Scanner scanner = new Scanner(new File("A-large.in"));
		PrintStream writer = new PrintStream(new File("output.txt"));
		int T = scanner.nextInt();
		for (int c= 0; c < T; c++){
			if (c > 0)
				scanner.nextLine();
			
			Character[][] chess = new Character[4][];
			Status s =Status.Draw;
			for (int i = 0; i < 4; i++)
			{
				chess[i] = new Character[4];
				String row = scanner.next();
				for (int j = 0; j< 4; j++){
					char ch = chess[i][j] = row.charAt(j);
					if (ch == '.'){
						s = Status.Incomplete;
					}
				}
				scanner.nextLine();
			}
			
			

			
			List<List<Character>> lists = getLists(chess);
			
			
			for (List<Character> list : lists){
				if (checkList(list, 'X')){
					s = Status.X;
					break;
				}
				else if (checkList(list, 'O')){
					s = Status.O;
					break;
				}
			}
			
			if (s == Status.X || s == Status.O){
				System.out.printf("Case #%d: %s won\n", c+1, s);
				writer.printf("Case #%d: %s won\n", c+1, s);
			}
			
			else if (s == Status.Incomplete){
				System.out.printf("Case #%d: Game has not completed\n", c + 1);
				writer.printf("Case #%d: Game has not completed\n", c + 1);
			}
			
			else{
				System.out.printf("Case #%d: Draw\n", c+1);
				writer.printf("Case #%d: Draw\n", c+1);
			}
			
		}
		
	}
	
	static List<List<Character>> getLists(Character[][] chess){
		List<List<Character>> lists = new ArrayList<List<Character>>();
		int n = chess.length;
		List<Character> diag1 = new ArrayList<Character>();
		List<Character> diag2 = new ArrayList<Character>();
		
		for (int i= 0; i < n; i++ ){
			// get a list for row 
			List<Character> list = Arrays.asList(chess[i]);
			lists.add(list);
			
			// get a list for column
			list = new ArrayList<Character>();
			for (int j = 0; j < n; j++){
				list.add(chess[j][i]);
			}
			lists.add(list);
			
			diag1.add(chess[i][i]);
			diag2.add(chess[i][n-1-i]);
		}
		
		lists.add(diag1);
		lists.add(diag2);
		return lists;
		
	}
	
	static boolean checkList(List<Character> list, char c){
		for (Character cl : list){
			if (cl != 'T' && cl != c){
				return false;
			}
		}
		return true;
	}
}
