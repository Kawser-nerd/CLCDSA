import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Scanner;


public class Cookie {

	public static void main( String[] args ) throws IOException{
		Scanner sc = new Scanner(new FileReader("jam.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("jam.out"));
		int cases;
		cases = sc.nextInt();
		for ( int z = 1 ; z <= cases ; z++ ){
			double C = sc.nextDouble();
			double F = sc.nextDouble();
			double X = sc.nextDouble();
			double product = 2;
			double ans = 0;
			while ( X/(product+F)+C/product < X/product ){
				ans += C/product;
				product += F;
			}
			ans += X/product;
			bw.write("Case #" + z + ": ");
			DecimalFormat df = new DecimalFormat("0.00000000");
			bw.write(""+ df.format(ans) + "\n");
		}
		sc.close();
		bw.close();
	}

}
