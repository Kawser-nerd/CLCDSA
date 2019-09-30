import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1);
        String s = r.readLine();
        int n = Integer.parseInt(s);
        s = r.readLine();
        String[] sl = s.split("[\\s]+");
        int a[] = new int[1000];
        for(int i = 0; i < n; i++)
        {
        	a[i] = Integer.parseInt(sl[i]);
        }
        
        int c = 99999999;
        for(int i = -100; i <= 100; i++)
        {
        	int v = 0;
        	for(int j = 0; j < n; j++)
        	{
        		v += (i - a[j]) * (i - a[j]);
        	}
        	c = Math.min(c, v);
        }
        
        System.out.println(c);
	}

}