import java.io.*;
import java.util.*;
import java.math.*;

public class CounterCulture {
	static int c;

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("out.out"));
		int t = Integer.parseInt(br.readLine());
		for(c = 1; c <= t; c++){
			bw.write("Case #" + c + ": ");
			String line = br.readLine();
			long num = Long.parseLong(line);
			// int count = 0;
			// if(num <= 20){
			// 	// bw.write(num + "\n");
			// 	count += num;
			// 	// continue;
			// }
			// if(num <= 100){ //<100
			// 	// bw.write(((num - 1) / 10 + 11 + (num - 1) % 10) + "\n");
			// 	count += (num - 1) / 10 + 11 + (num - 1) % 10;
			// }
			// else{
			// 	count += 29;
			// }
			bw.write(getCount(num) + "\n");
		}
		br.close();
		bw.close();
	}

	public static long getCount(long num){
		System.out.print(num + "   ");
		String n = (num - 1) + "";
		long count = 0;
		int length = n.length();
		if(length == 1){
			return num;
		}
		long incr = 0;
		if(length % 2 == 0){
			long prev = count;
			for(int i = 0; i < length / 2; i++){
				count += (n.charAt(i) - '0') * pow(10, i);
			}
			if(count > prev + 1){
				incr = 1;
			}
			for(int i = 0; i < length / 2; i++){
				count += (n.charAt(length - 1 - i) - '0') * pow(10, i);
			}
		}
		else{
			long prev = count;
			for(int i = 0; i < length / 2; i++){
				count += (n.charAt(i) - '0') * pow(10, i);
			}
			if(count > prev + 1){
				incr = 1;
			}
			for(int i = 0; i < length / 2 + 1; i++){
				count += (n.charAt(length - 1 - i) - '0') * pow(10, i);
			}
		}
		count += incr;
		System.out.println(count);
		return count + getCount(pow(10, length - 1));
	}

	public static long pow(long base, long e){
		if(e == 0){
			return 1;
		}
		if(e % 2 == 0){
			return pow(base * base, e / 2);
		}
		return base * pow(base, e - 1);
	}







}