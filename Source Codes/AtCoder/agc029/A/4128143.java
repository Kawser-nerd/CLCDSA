import java.io.IOException;
import java.io.InputStream;

public class Main {

	public static void main(String[] args) {
		InputStream in = System.in;
		final byte[] bytes = new byte[200001];
		int length = 0;
		try {
			length = in.read(bytes);
		} catch (IOException e) {
		}
		int count = 0;
		long sum = 0;
		for(int i = 0; i < length; i++) {
			if(bytes[i] == 'B')
				count++;
			else if(bytes[i] == 'W')
				sum += count;
		}
		System.out.println(sum);
	}

}