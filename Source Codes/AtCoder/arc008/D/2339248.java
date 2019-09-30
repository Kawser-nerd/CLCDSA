import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.TreeSet;

public class Main
{
  public static void main(String[] args) throws IOException
  {
    BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1);
    String[] sl = r.readLine().split("[\\s]+");
    // long n = Long.parseLong(sl[0]);
    long n = 1L;
    int m = Integer.parseInt(sl[1]);
    long pp[] = new long[m];
    double aa[] = new double[m];
    double bb[] = new double[m];

    HashMap<Long, Double> aleph = new HashMap<Long, Double>();
    HashMap<Long, Double> beth = new HashMap<Long, Double>();

    Double min = 1.0;
    Double max = 1.0;

    TreeSet<Long> ts = new TreeSet<>();
    for (int i = 0; i < m; i++)
    {
      sl = r.readLine().split("[\\s]+");
      pp[i] = Long.parseLong(sl[0]);
      ts.add(pp[i]);
      aa[i] = Double.parseDouble(sl[1]);
      bb[i] = Double.parseDouble(sl[2]);
    }
    
    for(n = 2L; n < m; n *= 2);
    n *= 2;
    
    HashMap<Long, Long> hm = new HashMap<Long, Long>();
    long z = 1;
    for(Long v : ts)
    {
      hm.put(v, z);
      z++;
    }
    
    for (int i = 0; i < m; i++)
    {
      long p = hm.get(pp[i]);
      double a = aa[i];
      double b = bb[i];
      p = n + p - 2;
      aleph.put(p, a);
      beth.put(p, b);
      while (p != 0)
      {
        p = (p - 1) / 2;
        long lf = p * 2 + 1;
        long rg = lf + 1;
        if (!aleph.containsKey(lf))
        {
          aleph.put(p, aleph.get(rg));
          beth.put(p, beth.get(rg));
        }
        else if (!aleph.containsKey(rg))
        {
          aleph.put(p, aleph.get(lf));
          beth.put(p, beth.get(lf));
        }
        else
        {
          aleph.put(p, aleph.get(lf) * aleph.get(rg));
          beth.put(p, aleph.get(rg) * beth.get(lf) + beth.get(rg));
        }
      }

      min = Math.min(aleph.get(0L) + beth.get(0L), min);
      max = Math.max(aleph.get(0L) + beth.get(0L), max);
    }

    System.out.println(min);
    System.out.println(max);

  }
}