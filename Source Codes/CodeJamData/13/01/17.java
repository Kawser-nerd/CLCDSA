import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;


public class TicTacToeTomek {
	
	public static boolean check(String[] map , char x){
		int count = 0;
		for(int i = 0 ; i < 4 ; i ++){
			count = 0;
			for(int j = 0 ; j < 4 ; j ++){
				if(map[i].charAt(j) == x || map[i].charAt(j) == 'T'){
					count ++;
				}
			}
			if(count == 4) return true;
			count = 0;
			for(int j = 0 ; j < 4 ; j ++){
				if(map[j].charAt(i) == x || map[j].charAt(i) == 'T')
					count ++;
			}
			if(count == 4) return true;
		}
		count = 0;
		for(int i = 0 ; i < 4 ; i ++){
			if(map[i].charAt(i) == x || map[i].charAt(i) == 'T')
				count ++;
		}
		if(count == 4) return true;
		count = 0;
		for(int i = 0 ; i < 4 ; i ++){
			if(map[i].charAt(3 - i) == x || map[i].charAt(3 - i) == 'T')
				count ++;
		}
		if(count == 4) return true;
		return false;
	}
	
	public static boolean isEnd(String[] map){
		for(int i = 0 ; i < 4 ; i ++){
			for(int j = 0 ; j < 4 ; j ++){
				if(map[i].charAt(j) == '.')
					return false;
			}
		}
		return true;
	}
	
	public static int check(String[] map){
		int result = -1;
		if(check(map , 'X')) result = 0;
		else if(check(map , 'O')) result = 1;
		else if(isEnd(map)) result = 2;
		return result;
	}
	
	public static void main(String args[]) throws Exception{
		Scanner in = new Scanner(new FileInputStream("A-large.in"));
		PrintWriter writer = new PrintWriter(new FileOutputStream("A-large.out"));
		int T = in.nextInt();
		for(int i = 0 ; i < T ; i ++){
			if(i > 0) in.nextLine();
			String[] map = new String[4];
			for(int j = 0 ; j < 4 ; j ++){
				map[j] = in.next();
			}
			int result = check(map);
			writer.write("Case #" + (i + 1) + ": ");
			switch(result){
			case 0: writer.println("X won"); break;
			case 1: writer.println("O won"); break;
			case 2: writer.println("Draw"); break;
			default: writer.println("Game has not completed"); break;
			}
		}
		in.close();
		writer.close();
	}

}
