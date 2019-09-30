import java.util.*;
import java.io.*;

class Main
{
	static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                     InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }

	public static void main (String[] args)
	{
		FastReader reader = new FastReader();
		int n = reader.nextInt();
		long[] array = new long[n+1];
		ArrayList<Long> value = new ArrayList<Long>();
		ArrayList<Long> index =  new ArrayList<Long>();
		ArrayList<Long> adder = new ArrayList<Long>();

		/*long one = 1;
		array[0] = (one<<20) - 1;
		value.add (array[0]);
		index.add (0);*/


		for (int i=0; i<n; i++)
		{
			array[i] = reader.nextLong();
			if (array[i] > 0)
			{
				value.add (array[i]);
				index.add ((long)i);
			}
		}

		long one = 1;
		array[n] = (one<<20) - 1;
		value.add (array[n]);
		index.add ((long)n);

		long ans = 0;

		long count = 0;
		for (int i=0; i<=n; i++)
		{
			if (array[i] == 0)
				count++;
			else
			{
				ans += ((count+1)*count)/2;

				adder.add (count);
				count = 0;
			}
		}

		for (int i=0; i<index.size(); i++)
		{
			long sum = 0;
			long xor = 0;

			int j = i;
			while (j < index.size())
			{
				if (sum+value.get(j) == (xor^value.get(j)))
				{
					sum += value.get(j);
					xor ^= value.get(j);
					j++;
				}
				else
				{
					ans += (index.get(j) - index.get(i)) * (adder.get(i) + 1);
					break;
				}
			}
		}



		System.out.println (ans);
	}
}