import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) throws IOException{
		Scanner scanner = new Scanner(System.in);
		//Scanner scanner = new Scanner(new FileInputStream(new File("B-large.in")));
		//FileOutputStream fo = new FileOutputStream(new File("output.out"));
		int t = scanner.nextInt();
		for(int x = 1; x <= t; ++x){
			int b = scanner.nextInt();
			long m = scanner.nextLong();
			System.out.print("Case #"+x+": ");
			//fo.write(("Case #"+x+": ").getBytes());
			if(m > Math.pow(2, b - 2)){
				System.out.print("IMPOSSIBLE\n");
				//fo.write(("IMPOSSIBLE\n").getBytes());
				continue;
			}
			else
				System.out.print("POSSIBLE\n");
				//fo.write(("POSSIBLE\n").getBytes());
			int[][] slides = new int[b][b];
			for(int i = 0; i < b; ++i){
				for(int j = i + 1; j < b; ++j){
					slides[i][j] = 1;
				}
			}
			String str = Long.toBinaryString(m-1) + "";
			if(str.equals("0"))
				str = "";
			while(str.length() < b - 1){
				str = "0" + str;
			}
			str += "1";
			//fo.write((str+"\n").getBytes());
			System.out.println(str);
			for(int i = 1; i < b; ++i){
				for(int j = 0; j < b; ++j){
					//fo.write((slides[i][j]+"").getBytes());
					System.out.print(slides[i][j]);
				}
				//fo.write(("\n").getBytes());
				System.out.print("\n");
			}
		}
	}
}
