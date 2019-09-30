import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) throws IOException{
		Scanner scanner = new Scanner(System.in);
		//Scanner scanner = new Scanner(new FileInputStream(new File("C-large.in")));
		//FileOutputStream fo = new FileOutputStream(new File("output.out"));
		int t = scanner.nextInt();
		for(int x = 1; x <= t; ++x){
			int j = scanner.nextInt();
			int p = scanner.nextInt();
			int s = scanner.nextInt();
			int k = scanner.nextInt();
			int s1 = Math.min(s, k);
			//fo.write(("Case #" + x + ": " + j * p * s1 + "\n").getBytes());
			System.out.print("Case #" + x + ": " + j * p * s1 + "\n");
			int count = 1, count2 = 1;
			for(int a = 1; a <= j; ++a){
				count = count2;
				++count2;
				for(int b = 1; b <= p; ++b){
					for(int c = 1; c <= s1; ++c){
						int c1 = (count++) % s;
						//fo.write((a + " " + b + " " + (c1 == 0 ? s : c1) + "\n").getBytes());
						System.out.print(a + " " + b + " " + (c1 == 0 ? s : c1) + "\n");
					}
				}
			}
		}
		//fo.flush();
		//fo.close();
	}
}
