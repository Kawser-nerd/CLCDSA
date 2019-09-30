import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;


public class Main {
	
	public static void main(String[] args) throws IOException{
		Scanner scanner = new Scanner(System.in);
		//Scanner scanner = new Scanner(new FileInputStream(new File("A-small-attempt0.in")));
		//FileOutputStream fo = new FileOutputStream(new File("output.out"));
		int t = scanner.nextInt();
		for(int x = 1; x <= t; ++x){
			int n = scanner.nextInt();
			int[] p = new int[n];
			for(int i = 0; i < n; ++i){
				p[i] = scanner.nextInt();
			}
			System.out.print("Case #" + x + ":");
			//fo.write(("Case #" + x + ":").getBytes());
			if(n == 2){
				for(int i = 0; i < p[0]; ++i){
					System.out.print(" AB");
					//fo.write((" AB").getBytes());
				}
				System.out.println();
				//fo.write(("\n").getBytes());
			}
			else{
				int count = count(p);
				while(count > 2){
					int index = findMax(p);
					--p[index];
					System.out.print(" " + (char)('A'+index));
					//fo.write((" " + (char)('A'+index)).getBytes());
					count = count(p);
				}
				int i1 = -1, i2 = -1;
				for(int i = 0; i < p.length; ++i){
					if(p[i] != 0){
						if(i1 == -1)
							i1 = i;
						else
							i2 = i;
					}
				}
				System.out.println(" " + (char)('A'+i1) + (char)('A'+i2));
				//fo.write((" " + (char)('A'+i1) + (char)('A'+i2) + '\n').getBytes());
			}
		}
		//fo.flush();
		//fo.close();
	}
	
	public static int count(int[] num){
		int count = 0;
		for(int i = 0; i < num.length; ++i)
			if(num[i] != 0)
				++count;
		return count;
	}
	
	public static int findMax(int[] num){
		int max = 0;
		int index = -1;
		for(int i = 0; i < num.length; ++i){
			if(num[i] > max){
				max = num[i];
				index = i;
			}
		}
		return index;
	}
	
}
