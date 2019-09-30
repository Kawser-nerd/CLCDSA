import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO ???????????????
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String A = br.readLine();
		String B = br.readLine();
		int lengths = A.length();
		//boolean Ab[] = new boolean[lengths];
		boolean Bb[] = new boolean[lengths];
		for(int i = 0; i < lengths; i++)
		{
			//Ab[i] = false;
			Bb[i] = false;
		}
		int k = 0;
		for(int i = 0;i < lengths;i++)
		{
			//System.out.println(i);
			if(i == 0)
			{
				for(int j = 0;;j++)
				{
					//System.out.println(A.substring(i, i+1).equals(B.substring(j, j+1)) + " " + A.substring(i, i+1) + " " + B);
					if(j == lengths)
					{
						System.out.println("No");
						System.exit(0);
					}
					if(!Bb[j] && A.substring(i, i+1).equals(B.substring(j, j+1)))
					{
						Bb[j] = true;
						k = j;
						break;
					}
				}
			}
			else
			{
				int l = k+i >= lengths ? k+i-lengths : k+i;
				//System.out.println(l + " " + i + " " + k + " " + lengths);
				if(!A.substring(i, i+1).equals(B.substring(l, l+1)))
				{
					i = -1;
				}
			}
		}
		System.out.println("Yes");
	}

}